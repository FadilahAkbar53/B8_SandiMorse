#include <stdio.h>
#include <stdlib.h>
#include "HeaderMorse.h"
#include "Morse.h"
#include "tampilan.h"

int main()
{
    TreeNode *morseTree = NULL;
    initialMorse(&morseTree);

    int choice;
    do
    {
        menuUtama();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1: // Baca file
        {
            printf("Baca file");
            readMessageFromFile(morseTree, "../input.txt");
            getchar();
        }
        break;
        case 2: // Terjemahan Sandi Morse
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
                fitur_decodeMorse(morseTree);
                getchar();
            }
            break;
            case 2:
            {
                fitur_encodeMorse(morseTree);
                getchar();
            }
            break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
            }
        }
        break;
        case 3: // Print Struktur hirarki Tree
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
                printf("Struktur Hirarki Sandi Morse\n");
                getchar();
                break;
            case 2:
                printf("Struktur huruf dalam hirarki sandi\n");
                getchar();
                break;
            default:
                break;
            }
        }
        break;
        case 4: // Percakapan user
        {
            int pilihanPengguna;
            menuPercakapan();
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
                user1Menu(morseTree);
            }
            break;
            case 2:
            {
                user2Menu(morseTree);
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
    } while (choice != 6);

    freeTree(morseTree);
    return 0;
}