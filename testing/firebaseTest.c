#include "../Feature.h"

void test_getAllUser() {
    int userCount;
    char **users = getAllUser(&userCount);

    if (users != NULL && userCount > 0) {
        printf("getAllUser Test Passed\n");
        free_usernames(users, userCount);
    } else {
        printf("getAllUser Test Failed\n");
    }
}

void test_getMessageFromFirebase() {
    int arraySize;
    const char *user = "user";

    // Mock the function call to getMessageFromFirebase
    message *messages = getMessageFromFirebase(user, &arraySize);

    if (messages != NULL) {
        printf("getMessageFromFirebase Test Passed\n");
        for (int i = 0; i < arraySize; i++) {
            free(messages[i].from);
            free(messages[i].message);
        }
        free(messages);
    } else {
        printf("getMessageFromFirebase Test Failed\n");
    }
}

void test_getDataFromFirebase() {
    const char *url = "https://example.com"; // Mock URL

    // Mock the function call to curl_easy_perform and response
    char *response = getDataFromFirebase(url);

    if (response != NULL) {
        printf("getDataFromFirebase Test Passed\n");
        free(response);
    } else {
        printf("getDataFromFirebase Test Failed\n");
    }
}

void test_formatJsonArray() {
    const char *jsonString = "{\"user1\":{\"message1\":\"Hello\"},\"user2\":{\"message2\":\"World\"}}";
    int arraySize;
    message *messages = formatJsonArray(jsonString, &arraySize);

    if (arraySize == 2 &&
        strcmp(messages[0].from, "message1") == 0 &&
        strcmp(messages[0].message, "Hello") == 0 &&
        strcmp(messages[1].from, "message2") == 0 &&
        strcmp(messages[1].message, "World") == 0) {
        printf("formatJsonArray Test Passed\n");
    } else {
        printf("formatJsonArray Test Failed\n");
    }

    free(messages[0].from);
    free(messages[0].message);
    free(messages[1].from);
    free(messages[1].message);
    free(messages);
}

void test_writeCallback() {
    char *data = (char *) malloc(1);
    data[0] = '\0';

    const char *input = "Hello, World!";
    size_t result = writeCallback((void *)input, 1, strlen(input), &data);

    if (result == strlen(input) && strcmp(data, "Hello, World!") == 0) {
        printf("writeCallback Test Passed\n");
    } else {
        printf("writeCallback Test Failed\n");
    }

    free(data);
}

void test_isValidUser() {
    char *users[] = {"user1", "user2", "user3"};
    int userCount = 3;

    if (isValidUser("user1", users, userCount) &&
        !isValidUser("user4", users, userCount)) {
        printf("isValidUser Test Passed\n");
    } else {
        printf("isValidUser Test Failed\n");
    }
}



int main() {
    // Initialize Morse tree
    TreeNode *root = createTreeNode('\0', NULL);
    initialMorse(&root);

    // Run tests
    test_writeCallback();
    test_formatJsonArray();
    test_getDataFromFirebase();
    test_getMessageFromFirebase();
    test_getAllUser();
    test_isValidUser();

    // Free Morse tree
    free(root);

    return 0;
}
