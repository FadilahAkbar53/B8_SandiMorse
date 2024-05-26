#include "Tampilan.h"

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
            system("cls");
            printf("Read from file\n");
            readMessageFromFile(morseTree,"File/input.txt");
            getchar();
            break;
        case 2: // Morse Code Translation
        {
            int pilihan2;
            system("cls");
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
                system("cls");
                fitur_decodeMorse(morseTree);
                printf("\nTekan apapun untuk kembali!");
                getchar();
                break;
            case 2:
                system("cls");
                fitur_encodeMorse(morseTree);
                printf("\nTekan apapun untuk kembali!");
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
            system("cls");
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
                system("cls");
                printf("Morse Code Hierarchy Structure\n");
                printInorder(morseTree); // Print the tree structure
                printf("\nTekan apapun untuk kembali!");
                getchar();
                break;
            case 2:
                system("cls");
                displayHierarchy(morseTree); // Print the letters in Morse hierarchy
                printf("\nTekan apapun untuk kembali!");
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
                printf("\nTekan apapun untuk kembali!");
                getchar();
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
