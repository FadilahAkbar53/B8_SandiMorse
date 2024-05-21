#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TreeNode
{
    char character;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent; // added parent pointer
} TreeNode;

TreeNode *createNode(char character)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->character = character;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL; // initialize parent pointer to NULL
    return newNode;
}

void insertMorseCode(TreeNode **root, const char *code, char character)
{
    if (*root == NULL)
    {
        *root = createNode('\0');
    }

    TreeNode *current = *root;
    while (*code)
    {
        if (*code == '.')
        {
            if (current->left == NULL)
            {
                current->left = createNode('\0');
                current->left->parent = current; // set parent pointer
            }
            current = current->left;
        }
        else if (*code == '-')
        {
            if (current->right == NULL)
            {
                current->right = createNode('\0');
                current->right->parent = current; // set parent pointer
            }
            current = current->right;
        }
        code++;
    }
    current->character = character;
}

void buildMorseTree(TreeNode **root)
{
    // Add Morse codes for letters
    insertMorseCode(root, ".-", 'A');
    insertMorseCode(root, "-...", 'B');
    insertMorseCode(root, "-.-.", 'C');
    insertMorseCode(root, "-..", 'D');
    insertMorseCode(root, ".", 'E');
    insertMorseCode(root, "..-.", 'F');
    insertMorseCode(root, "--.", 'G');
    insertMorseCode(root, "....", 'H');
    insertMorseCode(root, "..", 'I');
    insertMorseCode(root, ".---", 'J');
    insertMorseCode(root, "-.-", 'K');
    insertMorseCode(root, ".-..", 'L');
    insertMorseCode(root, "--", 'M');
    insertMorseCode(root, "-.", 'N');
    insertMorseCode(root, "---", 'O');
    insertMorseCode(root, ".--.", 'P');
    insertMorseCode(root, "--.-", 'Q');
    insertMorseCode(root, ".-.", 'R');
    insertMorseCode(root, "...", 'S');
    insertMorseCode(root, "-", 'T');
    insertMorseCode(root, "..-", 'U');
    insertMorseCode(root, "...-", 'V');
    insertMorseCode(root, ".--", 'W');
    insertMorseCode(root, "-..-", 'X');
    insertMorseCode(root, "-.--", 'Y');
    insertMorseCode(root, "--..", 'Z');

    // Add Morse codes for numbers
    insertMorseCode(root, "-----", '0');
    insertMorseCode(root, ".----", '1');
    insertMorseCode(root, "..---", '2');
    insertMorseCode(root, "...--", '3');
    insertMorseCode(root, "....-", '4');
    insertMorseCode(root, ".....", '5');
    insertMorseCode(root, "-....", '6');
    insertMorseCode(root, "--...", '7');
    insertMorseCode(root, "---..", '8');
    insertMorseCode(root, "----.", '9');

    // Add Morse code for space
    insertMorseCode(root, ".-.-.", ' ');
}

char searchMorseCode(TreeNode *root, const char *code)
{
    TreeNode *current = root;
    while (*code && current != NULL)
    {
        if (*code == '.')
        {
            current = current->left;
        }
        else if (*code == '-')
        {
            current = current->right;
        }
        code++;
    }
    return (current != NULL) ? current->character : '\0';
}

void findMorseCode(TreeNode *root, char character, char *buffer, int depth)
{
    if (root == NULL)
    {
        return;
    }
    if (root->character == character)
    {
        buffer[depth] = '\0';
        printf("%s ", buffer);
        return;
    }
    buffer[depth] = '.';
    findMorseCode(root->left, character, buffer, depth + 1);
    buffer[depth] = '-';
    findMorseCode(root->right, character, buffer, depth + 1);
}

void printMorseCode(TreeNode *root, const char *input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            printf(".-.-. ");
        }
        else
        {
            char buffer[100];
            findMorseCode(root, toupper(input[i]), buffer, 0);
        }
    }
    printf("\n");
}

void convertToMorseCode(TreeNode *root, const char *input, char *output)
{
    output[0] = '\0';
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            strcat(output, ".-.-. ");
        }
        else
        {
            char buffer[100];
            findMorseCode(root, toupper(input[i]), buffer, 0);
            strcat(output, buffer);
            strcat(output, " ");
        }
    }
    // Remove the trailing space
    output[strlen(output) - 1] = '\0';
}

void convertFromMorseCode(TreeNode *root, const char *input, char *output)
{
    char temp[100];
    output[0] = '\0';

    char *token = strtok((char *)input, " ");
    while (token != NULL)
    {
        TreeNode *current = root;
        for (int i = 0; i < strlen(token); i++)
        {
            if (token[i] == '.')
            {
                current = current->left;
            }
            else if (token[i] == '-')
            {
                current = current->right;
            }
        }
        if (current != NULL)
        {
            strncat(output, &current->character, 1);
        }
        else
        {
            strcat(output, "?");
        }
        token = strtok(NULL, " ");
    }
}

void freeTree(TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void featureConvertCharToMorse(TreeNode *root)
{
    char input[100];
    printf("Enter characters to convert to Morse Code: ");
    getchar(); // consume newline left in buffer
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    printMorseCode(root, input);
}

void featureConvertMorseToChar(TreeNode *root)
{
    char input[100];
    printf("Enter Morse Code to convert to characters (separate codes with spaces): ");
    getchar(); // consume newline left in buffer
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    char *token = strtok(input, " ");
    while (token != NULL)
    {
        char result = searchMorseCode(root, token);
        if (result != '\0')
        {
            printf("%c", result);
        }
        else
        {
            printf("?");
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void printHierarchy(TreeNode *root, char character, char *buffer, int depth)
{
    if (root == NULL)
    {
        return;
    }
    if (root->character == character)
    {
        buffer[depth] = '\0';
        printf("Path for %c:\n", character);
        TreeNode *current = root;
        while (current != NULL)
        {
            printf("  ");
            printf("%c\n", current->character);
            current = current->parent;
        }
        return;
    }
    printHierarchy(root->left, character, buffer, depth + 1);
    if (root->left != NULL && root->left->character == character)
    {
        return;
    }
    printHierarchy(root->right, character, buffer, depth + 1);
    if (root->right != NULL && root->right->character == character)
    {
        return;
    }
}

void featurePrintHierarchy(TreeNode *root)
{
    char input;
    printf("Enter character to see its hierarchy+ in Morse Tree: ");
    scanf(" %c", &input);
    char buffer[100] = "";
    printHierarchy(root, toupper(input), buffer, 0);
}

void printMorseTree(TreeNode *root, int depth)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }

    printf("%c\n", root->character);

    printMorseTree(root->left, depth + 1);
    printMorseTree(root->right, depth + 1);
}

void featurePrintMorseTree(TreeNode *root)
{
    printf("Morse Tree Structure:\n");
    printMorseTree(root, 0);
}

void writeFile(const char *filename, const char *message)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Unable to open file for writing");
        return;
    }
    fprintf(file, "%s", message);
    fclose(file);
}

void readFile(const char *filename, char *buffer)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Unable to open file for reading");
        return;
    }
    fgets(buffer, 1000, file);
    fclose(file);
}

void featureConversation(TreeNode *root, int user)
{
    char filenameWrite[20], filenameRead[20];
    if (user == 1)
    {
        strcpy(filenameWrite, "fileA.txt");
        strcpy(filenameRead, "fileB.txt");
    }
    else
    {
        strcpy(filenameWrite, "fileB.txt");
        strcpy(filenameRead, "fileA.txt");
    }

    int choice;
    printf("\nUser %d Menu:\n", user);
    printf("1. Write a message\n");
    printf("2. Read a message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline left in buffer

    if (choice == 1)
    {
        char message[1000];
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // remove newline character

        FILE *file = fopen(filenameWrite, "w");
        if (file == NULL)
        {
            printf("File %s not found\n", filenameWrite);
        }
        else
        {
            fprintf(file, "%s", message);
            fclose(file);
        }
    }
    else if (choice == 2)
    {
        char buffer[1000];
        FILE *file = fopen(filenameRead, "r");
        if (file == NULL)
        {
            printf("File %s not found\n", filenameRead);
        }
        else
        {
            fgets(buffer, sizeof(buffer), file);
            fclose(file);

            // Check if the read message is Morse code or plain text
            int isMorse = 1;
            for (int i = 0; i < strlen(buffer); i++)
            {
                if (buffer[i] != '.' && buffer[i] != '-' && buffer[i] != ' ' && buffer[i] != '\n')
                {
                    isMorse = 0;
                    break;
                }
            }

            if (isMorse)
            {
                char output[1000];
                convertFromMorseCode(root, buffer, output);
                printf("Message from User %d in characters: %s\n", (user == 1 ? 2 : 1), output);
            }
            else
            {
                char output[1000];
                convertToMorseCode(root, buffer, output);
                printf("\n\nMessage from User %d in Morse code: %s\n", (user == 1 ? 2 : 1), output);
            }
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

int main()
{
    TreeNode *morseTree = NULL;
    buildMorseTree(&morseTree);

    int choice;
    do
    {
        printf("\nMain Menu:\n");
        printf("1. Convert Character to Morse Code\n");
        printf("2. Convert Morse Code to Character\n");
        printf("3. Print Hierarchy of a Character\n");
        printf("4. Conversation as User 1\n");
        printf("5. Conversation as User 2\n");
        printf("6. Print Tree\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            featureConvertCharToMorse(morseTree);
            break;
        case 2:
            featureConvertMorseToChar(morseTree);
            break;
        case 3:
            featurePrintHierarchy(morseTree);
            break;
        case 4:
            featureConversation(morseTree, 1);
            break;
        case 5:
            featureConversation(morseTree, 2);
            break;
        case 6:
            printMorseTree(morseTree,0);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    freeTree(morseTree);
    return 0;
}
