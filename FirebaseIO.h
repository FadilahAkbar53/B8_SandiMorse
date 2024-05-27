#ifndef B8_SANDIMORSE_FIREBASEIO_H
#define B8_SANDIMORSE_FIREBASEIO_H

#include <stdio.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

typedef struct Message {
    char *from;
    char *message;
} message;

size_t writeCallback(void *ptr, size_t size, size_t nmemb, char **data);
message *formatJsonArray(const char *jsonString, int *arraySize);
char *getDataFromFirebase(const char *url);
message *getMessageFromFirebase(const char *user, int *arraySize);
char **getAllUser(int *count);
void free_usernames(char **usernames, int count);
void sendDataToFireBase(const char *url, cJSON *data, const char *method);
void createUser(const char *user);
void createMessage(const char *toUser, const char *fromUser, const char *message);


size_t writeCallback(void *ptr, size_t size, size_t nmemb, char **data) {
    size_t totalSize = size * nmemb;
    *data = (char *) realloc(*data, strlen(*data) + totalSize + 1);
    if (*data == NULL) {
        printf("Failed to reallocate memory!\n");
        return 0;
    }
    strncat(*data, (char *) ptr, totalSize);
    return totalSize;
}

message *formatJsonArray(const char *jsonString, int *arraySize) {
    cJSON *json = cJSON_Parse(jsonString);
    if (json == NULL) {
        printf("Error parsing JSON!\n");
        return NULL;
    }

    int count = cJSON_GetArraySize(json);
    message *formattedResult = (message *) malloc(count * sizeof(message));
    if (formattedResult == NULL) {
        printf("Memory allocation failed!\n");
        cJSON_Delete(json);
        return NULL;
    }

    int index = 0;
    cJSON *item;
    cJSON_ArrayForEach(item, json) {
        cJSON *innerObject = cJSON_GetObjectItem(json, item->string);
        if (!cJSON_IsObject(innerObject)) {
            printf("Expected an inner object!\n");
            continue;
        }

        cJSON *innerItem;
        cJSON_ArrayForEach(innerItem, innerObject) {
            formattedResult[index].from = strdup(innerItem->string);
            formattedResult[index].message = strdup(innerItem->valuestring);
            if (formattedResult[index].from == NULL || formattedResult[index].message == NULL) {
                printf("String duplication failed!\n");
                free(formattedResult);
                cJSON_Delete(json);
                return NULL;
            }
            index++;
        }
    }

    *arraySize = index;

    cJSON_Delete(json);

    return formattedResult;
}

char *getDataFromFirebase(const char *url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        char *response = (char *) malloc(1);
        response[0] = '\0';
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            curl_easy_cleanup(curl);
            return response;
        } else {
            printf("Failed to fetch data from Firebase! Error: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        free(response);
    }

    return NULL;
}

message *getMessageFromFirebase(const char *user, int *arraySize) {
    const char *baseUrl = "https://morse-b923d-default-rtdb.firebaseio.com/morse/";
    const char *suffix = "/message.json";

    size_t urlLength = strlen(baseUrl) + strlen(user) + strlen(suffix) + 1;

    char *url = (char *) malloc(urlLength * sizeof(char));
    if (url == NULL) {
        fprintf(stderr, "Gagal mengalokasikan memori\n");
    }

    sprintf(url, "%s%s%s", baseUrl, user, suffix);
//    printf("URL: %s\n", url);

    char *response = getDataFromFirebase(url);
    message *formattedResult = formatJsonArray(response, arraySize);
    free(response);
    free(url);

    return formattedResult;

}

char** getAllUser(int *count) {
    const char *url = "https://morse-b923d-default-rtdb.firebaseio.com/morse.json";
    char *json_data = getDataFromFirebase(url);
    cJSON *root = cJSON_Parse(json_data);
    if (root == NULL) {
        printf("Error parsing JSON\n");
        return NULL;
    }

    int user_count = cJSON_GetArraySize(root);
    char **usernames = malloc(user_count * sizeof(char*));

    if (usernames == NULL) {
        printf("Memory allocation failed\n");
        cJSON_Delete(root);
        return NULL;
    }

    cJSON *user = NULL;
    int i = 0;
    cJSON_ArrayForEach(user, root) {
        usernames[i] = strdup(user->string);
        if (usernames[i] == NULL) {
            printf("Memory allocation failed for username\n");
            // Free any already allocated usernames
            for (int j = 0; j < i; j++) {
                free(usernames[j]);
            }
            free(usernames);
            cJSON_Delete(root);
            return NULL;
        }
        i++;
    }

    *count = user_count;
    cJSON_Delete(root);
    return usernames;
}

void free_usernames(char **usernames, int count) {
    for (int i = 0; i < count; i++) {
        free(usernames[i]);
    }
    free(usernames);
}

void sendDataToFireBase(const char *url, cJSON *data, const char *method){
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        char *dataString = cJSON_Print(data);

        // Inisialisasi struct curl_slist
        struct curl_slist *headers = NULL;

        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dataString);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // Bersihkan memori dan handle
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        free(dataString);
    }
    curl_global_cleanup();

}

void createUser(const char *user) {
    CURL *curl;
    CURLcode res;

    char *url = "https://morse-b923d-default-rtdb.firebaseio.com/morse.json";

    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, user, "");

    printf("User 1: %s\n", cJSON_Print(json));

    sendDataToFireBase(url, json, "PATCH");
}

void createMessage( const char *toUser,const char *fromUser, const char *message) {
    const char *baseUrl = "https://morse-b923d-default-rtdb.firebaseio.com/morse/";
    const char *suffix = "/message.json";

    size_t urlLength = strlen(baseUrl) + strlen(toUser) + strlen(suffix) + 1;

    char *url = (char *) malloc(urlLength * sizeof(char));
    if (url == NULL) {
        fprintf(stderr, "Gagal mengalokasikan memori\n");
    }

    sprintf(url, "%s%s%s", baseUrl, toUser, suffix);

    CURL *curl;
    CURLcode res;

    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, fromUser, message);

//    printf("result : %s\n", cJSON_Print(json));

    sendDataToFireBase(url, json, "POST");

    free(url);

}

bool isValidUser(const char *inputString, char *arrayUser[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (strstr(inputString, arrayUser[i]) != NULL) {
            return true; // Mengembalikan true jika ditemukan elemen yang cocok
        }
    }
    return false; // Mengembalikan false jika tidak ada elemen yang cocok
}


#endif //B8_SANDIMORSE_FIREBASEIO_H
