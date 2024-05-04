#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {
    // Buat tree dan sisipkan alfabet
    node *root = createNode(' ');
    insertCodeMorse(&root, 'E', "."); // .
    insertCodeMorse(&root, 'T', "-"); // -
    insertCodeMorse(&root, 'I', ".."); // ..
    insertCodeMorse(&root, 'A', ".-"); // .-
    insertCodeMorse(&root, 'N', "-."); // -.
    insertCodeMorse(&root, 'M', "--"); // --
    insertCodeMorse(&root, 'S', "..."); // ...
    insertCodeMorse(&root, 'U', "..-"); // ..-
    insertCodeMorse(&root, 'R', ".-."); // .-.
    insertCodeMorse(&root, 'W', ".--"); // .--
    insertCodeMorse(&root, 'D', "-.."); // -..
    insertCodeMorse(&root, 'K', "-.-"); // -.-
    insertCodeMorse(&root, 'G', "--."); // --.
    insertCodeMorse(&root, 'O', "---"); // ---
    insertCodeMorse(&root, 'H', "...."); // ....
    insertCodeMorse(&root, 'V', "...-"); // ...-
    insertCodeMorse(&root, 'F', "..-."); // ..-.
    insertCodeMorse(&root, 'L', ".-.."); // .-..
    insertCodeMorse(&root, 'P', ".--."); // .--.
    insertCodeMorse(&root, 'J', ".---"); // .---
    insertCodeMorse(&root, 'B', "-..."); // -...
    insertCodeMorse(&root, 'X', "-..-"); // -..-
    insertCodeMorse(&root, 'C', "-.-."); // -.-
    insertCodeMorse(&root, 'Y', "-.--"); // -.--
    insertCodeMorse(&root, 'Z', "--.."); // --..
    insertCodeMorse(&root, 'Q', "--.-"); // --.-

    int choice;

    printf("Menu:\n");
    printf("1. Konversi File Input\n");
    printf("2. Terjemahkan Morse (CLI)\n");
    printf("3. Tampilkan Pohon\n");
    printf("4. Percakapan\n");
    printf("Pilihan Anda: ");
    scanf("%d", &choice);
    getchar(); // Tangkap karakter newline

    switch (choice) {
        case 1:
            {
                FILE *file;
                file = fopen("input.txt", "r");
                if (file == NULL) {
                    printf("File tidak ditemukan!\n");
                    return 1;
                }
                char line[100];
                if (fgets(line, sizeof(line), file) == NULL) {
                    printf("Gagal membaca baris pertama dari file!\n");
                    fclose(file);
                    return 1;
                }
                if (strcmp(line, "sandi\n") == 0) {
                    while (fgets(line, sizeof(line), file)) {
                        printf("kalimat: %s", line);
                    }
                }else if(strcmp(line, "kalimat\n") == 0){
                    // Membaca dan mencetak baris-baris berikutnya
                    while (fgets(line, sizeof(line), file)) {
                        printf("kalimat: %s", line);
                    }
                }

                else {
                    printf("Format file tidak valid!\n");
                    fclose(file);
                    return 1;
                }



                fclose(file);
            }
            break;
        case 2:
            {
                char morseCode[100];
                printf("Masukkan kalimat Morse: ");
                fgets(morseCode, sizeof(morseCode), stdin);
//                printf("Kalimat: %s\n", decodeMorseCode(root, morseCode));
            }
            break;
        case 3:
            {
                char karakter;
                printf("Masukkan karakter: ");
                scanf("%c", &karakter);
                getchar(); // Tangkap karakter newline
//                printf("Sandi Morse: %s\n", encodeCharacter(karakter));
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
//                    char* morse = encodeCharacter(kalimat[i]);
//                    if (strcmp(morse, "") == 0) {
//                        printf("Karakter '%c' tidak dapat dikodekan.\n", kalimat[i]);
//                    } else {
//                        printf("%s ", morse);
//                    }
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
