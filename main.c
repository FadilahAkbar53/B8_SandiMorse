#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "tampilan.c"

int main()
{
    // Buat tree dan sisipkan alfabet
    node *root = createNode(' ');
    insertCodeMorse(&root, 'E', ".");    // .
    insertCodeMorse(&root, 'T', "-");    // -
    insertCodeMorse(&root, 'I', "..");   // ..
    insertCodeMorse(&root, 'A', ".-");   // .-
    insertCodeMorse(&root, 'N', "-.");   // -.
    insertCodeMorse(&root, 'M', "--");   // --
    insertCodeMorse(&root, 'S', "...");  // ...
    insertCodeMorse(&root, 'U', "..-");  // ..-
    insertCodeMorse(&root, 'R', ".-.");  // .-.
    insertCodeMorse(&root, 'W', ".--");  // .--
    insertCodeMorse(&root, 'D', "-..");  // -..
    insertCodeMorse(&root, 'K', "-.-");  // -.-
    insertCodeMorse(&root, 'G', "--.");  // --.
    insertCodeMorse(&root, 'O', "---");  // ---
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

    root = createNewTreeNode(' ', "");
    insertAlphabet(root);

    char kalimat[50], morseCode[50];

    while (1)
    {
        int choice;
        menuUtama();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
        {
            printf("Baca file");
        }
        break;
        case 2:
        {
            int pilihan2;
            menuTerjemah();
            scanf("%d", &pilihan2);
            getchar();

            if (pilihan2 == 0)
            {
                break; // Kembali ke menu utama
            }

            switch (pilihan2)
            {
            case 1:
            {
                printf("Masukkan sandi Morse: ");
                fgets(morseCode, sizeof(morseCode), stdin);
                printf("Karakter: %c\n", decodeMorse(root, morseCode));
                getchar();
            }
            break;
            case 2:
            {
                printf("Masukkan kalimat: ");
                fgets(kalimat, sizeof(kalimat), stdin);
                printf("Sandi Morse:\n");
                for (int i = 0; i < strlen(kalimat); i++)
                {
                    if (kalimat[i] == ' ')
                    {
                        printf(" ");
                        continue;
                    }
                    char *morse = encodeCharacter(kalimat[i]);
                    if (strcmp(morse, " ") == 0)
                    {
                        printf("Karakter '%c' tidak dapat dikodekan.\n", kalimat[i]);
                    }
                    else
                    {
                        printf("%s ", morse);
                    }
                }
                printf("\n");
                getchar();
            }
            break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
            }
        }
        break;
        case 3:
        {
            int pilihan3;
            menuHirarki();
            scanf("%d", &pilihan3);
            getchar();

            if (pilihan3 == 0)
            {
                break; // Kembali ke menu utama
            }

            switch (pilihan3)
            {
            case 1:
                hirarkiSandiMorse();
                getchar();
                break;
            case 2:
                printf("Masukan Karakter : \n\n");
                getchar();
                break;
            default:
                break;
            }
        }
        break;
        case 4:
        {
            int pilihan4, pilihanPengguna;
            menuPercakapan();
            scanf("%d", &pilihan4);
            getchar();

            if (pilihan4 == 0)
            {
                break; // Kembali ke menu utama
            }

            switch (pilihan4)
            {
            case 1:
            {
                menuPengguna1();
                scanf("%d", &pilihanPengguna);
                getchar();

                if (pilihanPengguna == 0)
                {
                    break; // Kembali ke menu utama
                }

                switch (pilihanPengguna)
                {
                case 1:
                {
                    printf("Silahkan Masukan Pesan : ");
                }
                break;
                case 2:
                {
                    printf("Pesan Dari Pengguna 2 Adalah : ");
                }
                break;
                default:
                    break;
                }
            }
            break;
            case 2:
            {
                menuPengguna2();
                scanf("%d", &pilihanPengguna);
                getchar();

                if (pilihanPengguna == 0)
                {
                    break; // Kembali ke menu utama
                }

                switch (pilihanPengguna)
                {
                case 1:
                {
                    printf("Silahkan Masukan Pesan : ");
                }
                break;
                case 2:
                {
                    printf("Pesan Dari Pengguna 1 Adalah : ");
                    getchar();
                }
                break;
                default:
                    break;
                }
            }
            break;
            default:
                break;
            }
        }
        break;
        case 0:
            printf("Terima kasih!\n");
            return 0; // Keluar dari program
        default:
            printf("Pilihan tidak valid!\n");
            break;
        }
    }

    return 0;
}
