#include "Feature.h"

int main() {
    TreeNode *morseTree = NULL;
    char startChar;
    char endChar;
    initialMorse(&morseTree);
    int choice;
    selamatDatang();
    do {
        menuUtama();
        scanf("%d", &choice);
        printf("\n");
        getchar();
        switch (choice) {
            case 1: // Read from file
                bacaFileInput();
                readMessageFromFile(morseTree, "File/input.txt");
                getchar();
                break;
            case 2: // Morse Code Translation1
            {
                int pilihan2;
                menuTerjemah();
                scanf("%d", &pilihan2);
                getchar();

                if (pilihan2 == 0) {
                    break; // Back to main menu
                }

                switch (pilihan2) {
                    case 1:
                        fitur_decodeMorse(morseTree);
                        getchar();
                        break;
                    case 2:
                        fitur_encodeMorse(morseTree);
                        getchar();
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
            }
            break;
            case 3: // Print Tree Hierarchy
            {
                int pilihan3;
                menuHirarki();
                scanf("%d", &pilihan3);
                getchar();

                if (pilihan3 == 0) {
                    break; // Back to main menu
                }

                switch (pilihan3) {
                    case 1:
                        printf("\n\nMorse Code Hierarchy Structure\n");
                        printInorder(morseTree); // Print the tree structure
                        getchar();
                        break;
                    case 2:
                        displayHierarchy(morseTree); // Print the letters in Morse hierarchy
                        getchar();
                        break;
                    case 3: // Path between characters
                        printf("\n\nEnter the start character: ");
                        scanf(" %c", &startChar);
                        getchar();
                        printf("Enter the end character: ");
                        scanf(" %c", &endChar);
                        getchar();
                        findPath(morseTree, toupper(startChar), toupper(endChar));
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
            }
            break;
            case 4: // Conversation
            {
                int pilihanPengguna;
                menuPercakapan();
                scanf("%d", &pilihanPengguna);
                getchar();

                if (pilihanPengguna == 0) {
                    break; // Back to main menu
                }

                switch (pilihanPengguna) {
                    case 1:
                        user1Menu(morseTree);
                        break;
                    case 2:
                        user2Menu(morseTree);
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
            }
            break;
            case 5: // User Login
            int pilihanPenggunaOnline;
                menuPercakapanOnline();
                scanf("%d", &pilihanPenggunaOnline);
                getchar();
                if (pilihanPenggunaOnline == 0) {
                    break; // Back to main menu
                }
                    switch (pilihanPenggunaOnline) {
                        case 1:
                            printf("Menambahkan user baru\n");
                            char *newUser = readInput();
                            createUser(newUser);
                            free(newUser);
                            getchar();
                            break;
                        case 2:
                            menuloginUser();
                    char *userLogged = fitur_getUser(false);
                    if (userLogged != NULL) {
                        printf("User %s is online\n", userLogged);
                        menuPenggunaOnline(userLogged);
                        int choisedmenu;
                        scanf("%d", &choisedmenu);
                        getchar();
                        while (choisedmenu != 0) {
                            switch (choisedmenu) {
                                case 1:
                                    char *toUser = fitur_getUser(true);
                                    printf(" menulis pesan ke %s", toUser);
                                    char *messages = readInput();
                                    createMessage(toUser, userLogged, messages);
                                    free(toUser);
                                    free(messages);
                                    break;
                                case 2:
                                    printf("\nMembaca pesan dari pengguna lain\n");
                                    int arraySize;
                                    message *result = getMessageFromFirebase(userLogged, &arraySize);
                                    if (result != NULL) {
                                        for (int i = 0; i < arraySize; i++) {
                                            printf("\nFrom %s : \n", result[i].from);
                                            printf("Original Message :%s\n", result[i].message);
                                            printf("karakter : "); 
                                            char *token = strtok(result[i].message, " ");
                                                while (token != NULL) {
                                                char resultChar = decode(morseTree, token);
                                                if (resultChar != '\0') {
                                                    printf("%c", resultChar);
                                                } else {
                                                    printf("?");
                                                }
                                                token = strtok(NULL, " ");
                                            }
                                            printf("\n");
                                            free(result[i].from);
                                            free(result[i].message);
                                        }
                                        free(result);
                                    }
                                    getchar();
                                    printf("Membaca pesan dari pengguna lain\n");
                                    break;
                                case 0:
                                    printf("Kembali ke menu utama\n");
                                    break;
                                default:
                                    printf("Invalid choice!\n");
                                    break;
                            }
                            menuPenggunaOnline(userLogged);
                            scanf("%d", &choisedmenu);
                            getchar();
                        }
                        free(userLogged);
                    }
                            break;
                        default:
                            printf("Invalid choice!\n");
                        break;
                }
                break;
            case 0:
                penutup();
                break;
            default:
                printf("Pilihan yang anda inputkan tidak ada!\n");
                getchar();
                break;
        }
    } while (choice != 0);
    freeTree(morseTree);
    return 0;
}
