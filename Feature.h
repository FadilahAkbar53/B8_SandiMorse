
#ifndef B8_SANDIMORSE_FEATURE_H
#define B8_SANDIMORSE_FEATURE_H

#include "Morse.h"
#include "FirebaseIO.h"

// Fungsi untuk membaca input dari pengguna menggunakan linked list
char *readInput() {
    node *inputList = NULL;
    int ch;

    printf("\nMasukkan input (akhiri dengan Enter): \n");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        insertLast(&inputList, (char) ch);
    }

    // Konversi linked list menjadi string
    char *input = linkedListToString(inputList);

    // Bebaskan memori linked list
    freeLinkedList(&inputList);

    return input;
}

// Fungsi untuk menulis pesan ke file
void writeMessageToFile(const char *filename) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error membuka file untuk menulis.\n");
        return;
    }

    char *input = readInput();
    fprintf(file, "\n%s", input);

    fclose(file);
    free(input);
    printf("Pesan telah ditulis ke file %s.\n", filename);
}

// Fungsi untuk membaca pesan dari file
void readMessageFromFile(TreeNode *root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error membuka file untuk membaca.\n");
        return;
    }

    node *inputList = NULL;
    int ch;

    // Baca file karakter demi karakter
    while ((ch = fgetc(file)) != EOF) {
        if (ch != '\n') {
            insertLast(&inputList, (char) ch);
        } else {
            // Konversi linked list menjadi string
            char *line = linkedListToString(inputList);
            if (line == NULL) {
                printf("Gagal mengalokasikan memori\n");
                fclose(file);
                freeLinkedList(&inputList);
                return;
            }

            // Cek apakah baris tersebut berisi kode Morse atau karakter biasa
            int isMorseCode = 1;
            for (int i = 0; i < strlen(line); i++) {
                if (!strchr(".- ", line[i])) {
                    isMorseCode = 0;
                    break;
                }
            }

            if (isMorseCode) {
                printf("Pesan asli (Kode Morse):\n %s\n\n", line);

                // Konversi kode Morse menjadi karakter
                printf("Karakter: ");
                printf("\n");
                char *token = strtok(line, " ");
                while (token != NULL) {
                    char result = decode(root, token);
                    if (result != '\0') {
                        printf("%c", result);
                    } else {
                        printf("?");
                    }
                    token = strtok(NULL, " ");
                }
                printf("\n");
            } else {
                printf("Pesan asli:\n %s\n\n", line);

                // Konversi menjadi kode Morse
                printf("Kode Morse: \n");
                printMorseCode(root, line);
                printf("\n");
            }

            free(line);
            freeLinkedList(&inputList);  // Kosongkan linked list untuk baris berikutnya
        }
    }

    // Tangani baris terakhir jika tidak diakhiri dengan newline
    if (inputList != NULL) {
        char *line = linkedListToString(inputList);
        if (line == NULL) {
            printf("Gagal mengalokasikan memori\n");
            fclose(file);
            freeLinkedList(&inputList);
            return;
        }

        int isMorseCode = 1;
        for (int i = 0; i < strlen(line); i++) {
            if (!strchr(".- ", line[i])) {
                isMorseCode = 0;
                break;
            }
        }

        if (isMorseCode) {
            printf("Pesan asli (Kode Morse):\n %s\n\n", line);

            // Konversi kode Morse menjadi karakter
            printf("Karakter: ");
            printf("\n");
            char *token = strtok(line, " ");
            while (token != NULL) {
                char result = decode(root, token);
                if (result != '\0') {
                    printf("%c", result);
                } else {
                    printf("?");
                }
                token = strtok(NULL, " ");
            }
            printf("\n");
        } else {
            printf("Pesan asli:\n %s\n\n", line);

            // Konversi menjadi kode Morse
            printf("Kode Morse: \n");
            printMorseCode(root, line);
            printf("\n");
        }

        free(line);
    }

    freeLinkedList(&inputList);
    fclose(file);
}

void user1Menu(TreeNode *root) {
    int choice;
    while (1) {
        menuPengguna1();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                writeMessageToFile("File/user1.txt");
                getchar();
                break;
            case 2:
                readMessageFromFile(root, "File/user2.txt");
                getchar();
                break;
            case 0:
                return;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

// Fungsi menu untuk pengguna 2
void user2Menu(TreeNode *root) {
    int choice;
    while (1) {
        menuPengguna2();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                writeMessageToFile("File/user2.txt");
                getchar();
                break;
            case 2:
                readMessageFromFile(root, "File/user1.txt");
                getchar();
                break;
            case 0:
                return;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

void fitur_encodeMorse(TreeNode *root) {
    char *input = readInput();
    if (input == NULL) {
        return;
    }

    printf("\nMorse Code:\n");
    char *morseCode = encode(root, input);
    if (morseCode != NULL) {
        printf("%s\n", morseCode);
        free(morseCode);
    }
    free(input);
}

void fitur_decodeMorse(TreeNode *root) {
    char *input = readInput();
    printf("\nCharacters:\n");
    char *token = strtok(input, " ");
    while (token != NULL) {
        char result = decode(root, token);
        if (result != '\0') {
            printf("%c", result);
        } else {
            printf("?");
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
    free(input);
}

void printInorder(TreeNode *root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%c ", root->character);
        printInorder(root->right);
    }
}

// Fungsi untuk mencetak hierarki dari root ke karakter target
void hierarchyRoot(TreeNode *root, char target, int level, bool *found) {
    if (root == NULL) {
        return;
    }

    // Traversing subtree kiri terlebih dahulu
    hierarchyRoot(root->left, target, level + 1, found);

    // Cetak karakter node saat ini
    if (!*found) // Cetak hanya jika target belum ditemukan
    {
        printf("%c", root->character);
    }

    // Cek apakah node saat ini adalah target
    if (root->character == target) {
        *found = true; // Set found ke true untuk menghentikan pencetakan lebih lanjut
        return;
    }

    // Traversing subtree kanan terakhir
    hierarchyRoot(root->right, target, level + 1, found);
}

// Fungsi untuk menemukan dan mencetak hierarki dari root ke karakter target
void findhierarchyRoot(TreeNode *root, char target) {
    bool found = false;
    hierarchyRoot(root, target, 0, &found);
    if (!found) {
        printf("Karakter '%c' tidak ditemukan dalam pohon Morse.\n", target);
    }
    getchar();
}


// Fungsi untuk meminta karakter dari pengguna dan menampilkan hierarkinya
void displayHierarchy(TreeNode *root) {
    char inputChar;
    printf("Masukkan karakter untuk menemukan hierarkinya: ");
    scanf(" %c", &inputChar);

    printf("Hierarki untuk karakter '%c':\n", inputChar);
    findhierarchyRoot(root, toupper(inputChar));
}

// Fungsi untuk menemukan jalur dari node ke root
int findPathToRoot(TreeNode *node, char *path, int *PathDirec) {
    int length = 0;
    while (node != NULL) {
        path[length] = node->character;
        PathDirec[length] = (node->parent && node->parent->right == node) ? 1 : 0; // kanan:1, kiri:0
        node = node->parent;
        length++;
    }
    return length;
}

// Fungsi untuk menemukan jalur antara dua karakter
void findPath(TreeNode *root, char start, char end) {
    TreeNode *startNode = searchNodeMorse(root, start);
    TreeNode *endNode = searchNodeMorse(root, end);

    if (startNode == NULL) {
        printf("Start character '%c' not found in the Morse tree.\n", start);
        return;
    }

    if (endNode == NULL) {
        printf("End character '%c' not found in the Morse tree.\n", end);
        return;
    }

    char pathStart[100], pathEnd[100];
    int sidePathStart[100], sidePathEnd[100];
    int pathStartLen = findPathToRoot(startNode, pathStart, sidePathStart);
    int pathEndLen = findPathToRoot(endNode, pathEnd, sidePathEnd);

    // Temukan leluhur bersama terendah (LCA)
    int i = pathStartLen - 1;
    int j = pathEndLen - 1;
    while (i >= 0 && j >= 0 && pathStart[i] == pathEnd[j]) {
        i--;
        j--;
    }

    // Cetak jalur dari karakter awal ke LCA (tidak termasuk LCA)
    printf("Path from '%c' to '%c': ", start, end);
    for (int k = 0; k <= i; k++) {
        if (sidePathStart[k] == 0 || k == 0) {  // Cetak hanya jika itu adalah anak kiri atau karakter pertama
            printf("%c ", pathStart[k]);
        }
    }

    // Cetak jalur dari LCA ke karakter akhir
    for (int k = j + 1; k >= 0; k--) {
        printf("%c ", pathEnd[k]);
    }
    printf("\n");
    getchar();
}

char* fitur_getUser(bool showUser) {
    int user_count = 0;
    char **usernames = getAllUser(&user_count);
    if (usernames != NULL) {
        if (showUser) {
            for (int i = 0; i < user_count; i++) {
                printf("|%13s %-20s |\n", "", usernames[i]);
            }
        }
        char *user = readInput();
        if (isValidUser(user, usernames, user_count)) {
            // Bebaskan memori untuk setiap username
            for (int i = 0; i < user_count; i++) {
                free(usernames[i]);
            }
            // Bebaskan memori array usernames
            free(usernames);
            return user;
        } else {
            // Bebaskan memori untuk setiap username
            for (int i = 0; i < user_count; i++) {
                free(usernames[i]);
            }
            // Bebaskan memori array usernames
            free(usernames);
            printf("User %s tidak ditemukan\n", user);
            free(user);
            return NULL;
        }
    } else {
        printf("Failed to retrieve usernames\n");
        return NULL;
    }
}

#endif //B8_SANDIMORSE_FEATURE_H
