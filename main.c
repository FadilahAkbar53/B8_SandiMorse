#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bangkong.c"

int main() {
    // Buat tree dan sisipkan alfabet
    root = createNewTreeNode(' ', "");
    insertAlphabet(root);

    int choice;

    printf("Menu:\n");
    printf("1. Konversi karakter Morse ke karakter\n");
    printf("2. Konversi kalimat Morse ke karakter\n");
    printf("3. Konversi karakter ke karakter Morse\n");
    printf("4. Konversi kalimat ke karakter Morse\n");
    printf("Pilihan Anda: ");
    scanf("%d", &choice);
    getchar(); // Tangkap karakter newline

    switch (choice) {
        case 1:
            {
                char morseCode[100];
                printf("Masukkan sandi Morse: ");
                fgets(morseCode, sizeof(morseCode), stdin);
                printf("Karakter: %c\n", decodeMorse(root, morseCode));
            }
            break;
        case 2:
            {
                char morseCode[100];
                printf("Masukkan kalimat Morse: ");
                fgets(morseCode, sizeof(morseCode), stdin);
                printf("Kalimat: %s\n", decodeMorseCode(root, morseCode));
            }
            break;
        case 3:
            {
                char karakter;
                printf("Masukkan karakter: ");
                scanf("%c", &karakter);
                getchar(); // Tangkap karakter newline
                printf("Sandi Morse: %s\n", encodeCharacter(karakter));
            }
            break;
        case 4:
            {
                char kalimat[100];
                printf("Masukkan kalimat: ");
                fgets(kalimat, sizeof(kalimat), stdin);
                printf("Sandi Morse:\n");
                for (int i = 0; i < strlen(kalimat); i++) {
                    if (kalimat[i] == ' ') {
                        printf(" ");
                        continue;
                    }
                    char* morse = encodeCharacter(kalimat[i]);
                    if (strcmp(morse, "") == 0) {
                        printf("Karakter '%c' tidak dapat dikodekan.\n", kalimat[i]);
                    } else {
                        printf("%s ", morse);
                    }
                }
                printf("\n");
            }
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
    }

    return 0;
}
