#include <stdio.h>
#include <stdlib.h>
#include "Morse.h"
#include "tampilan.h"

int main()
{
    TreeNode *morseTree = NULL;
    char input;
    char startChar; 
    char endChar;
    initialMorse(&morseTree);

    int choice;
    do
    {
        menuUtama();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1: // Read from file
            printf("Read from file\n");
            readMessageFromFile(morseTree,"../input.txt");
            getchar();
            break;
        case 2: // Morse Code Translation
        {
            int pilihan2;
            menuTerjemah();
            scanf("%d", &pilihan2);
            getchar();

            if (pilihan2 == 0)
            {
                break; // Back to main menu
            }

            switch (pilihan2)
            {
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

            if (pilihan3 == 0)
            {
                break; // Back to main menu
            }

            switch (pilihan3)
            {
            case 1:
                printf("Morse Code Hierarchy Structure\n");
                printInorder(morseTree); // Print the tree structure
                getchar();
                break;
            case 2:
                displayHierarchy(morseTree); // Print the letters in Morse hierarchy
                getchar();
                break;
            case 3: // Path between characters
                printf("Enter the start character: ");
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
            printf("Thank you!\n");
            break; // Exit the program
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 0);

    freeTree(morseTree);
    return 0;
}
