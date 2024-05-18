#ifndef MORSE_H
#define MORSE_H

#include "HeaderMorse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

TreeNode *createMorseTree(char character)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->character = character;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertCodeMorse(TreeNode **root, const char *code, char character)
{
    if (*root == NULL)
    {
        *root = createMorseTree('\0');
    }

    TreeNode *current = *root;
    while (*code)
    {
        if (*code == '.')
        {
            if (current->left == NULL)
            {
                current->left = createMorseTree('\0');
            }
            current = current->left;
        }
        else if (*code == '-')
        {
            if (current->right == NULL)
            {
                current->right = createMorseTree('\0');
            }
            current = current->right;
        }
        code++;
    }
    current->character = character;
}

void initialMorse(TreeNode **root)
{
    // Add Morse codes for letters
    insertCodeMorse(root, ".-", 'A');
    insertCodeMorse(root, "-...", 'B');
    insertCodeMorse(root, "-.-.", 'C');
    insertCodeMorse(root, "-..", 'D');
    insertCodeMorse(root, ".", 'E');
    insertCodeMorse(root, "..-.", 'F');
    insertCodeMorse(root, "--.", 'G');
    insertCodeMorse(root, "....", 'H');
    insertCodeMorse(root, "..", 'I');
    insertCodeMorse(root, ".---", 'J');
    insertCodeMorse(root, "-.-", 'K');
    insertCodeMorse(root, ".-..", 'L');
    insertCodeMorse(root, "--", 'M');
    insertCodeMorse(root, "-.", 'N');
    insertCodeMorse(root, "---", 'O');
    insertCodeMorse(root, ".--.", 'P');
    insertCodeMorse(root, "--.-", 'Q');
    insertCodeMorse(root, ".-.", 'R');
    insertCodeMorse(root, "...", 'S');
    insertCodeMorse(root, "-", 'T');
    insertCodeMorse(root, "..-", 'U');
    insertCodeMorse(root, "...-", 'V');
    insertCodeMorse(root, ".--", 'W');
    insertCodeMorse(root, "-..-", 'X');
    insertCodeMorse(root, "-.--", 'Y');
    insertCodeMorse(root, "--..", 'Z');

    // Add Morse codes for numbers
    insertCodeMorse(root, "-----", '0');
    insertCodeMorse(root, ".----", '1');
    insertCodeMorse(root, "..---", '2');
    insertCodeMorse(root, "...--", '3');
    insertCodeMorse(root, "....-", '4');
    insertCodeMorse(root, ".....", '5');
    insertCodeMorse(root, "-....", '6');
    insertCodeMorse(root, "--...", '7');
    insertCodeMorse(root, "---..", '8');
    insertCodeMorse(root, "----.", '9');

    // Add Morse code for space
    insertCodeMorse(root, ".-..-.", ' ');

    // Add Morse code for symbol
    insertCodeMorse(root, "..--..", '?');
    insertCodeMorse(root, "-.-.--", '!');
    insertCodeMorse(root, "---...", ':');
    insertCodeMorse(root, "-.-.-.", ';');
    insertCodeMorse(root, "--..--", ',');
    insertCodeMorse(root, "-...-", '=');
    insertCodeMorse(root, "-..-.", '/');
    insertCodeMorse(root, "-.---.", '(');
    insertCodeMorse(root, "-.--.-", ')');
    insertCodeMorse(root, "-....-", '-');
    insertCodeMorse(root, ".-.-.", '+');
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
            printf(".-..-. ");
        }
        else
        {
            char buffer[100];
            findMorseCode(root, toupper(input[i]), buffer, 0);
        }
    }
    printf("\n");
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

char *readInput()
{
    char *input = NULL;
    size_t size = 0;
    printf("\nEnter input (end with Enter): ");
    size_t len = getline(&input, &size, stdin);
    if (len == -1)
    {
        printf("Error reading input.\n");
        exit(1);
    }
    input[len - 1] = '\0'; // remove newline character
    return input;
}

/*FITUR FITUR*/

void writeMessageToFile(const char *filename)
{
    FILE *file = fopen(filename, "a+");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    char *input = readInput();
    fprintf(file, "\n%s", input);

    fclose(file);
    free(input);
    printf("Message written to file %s.\n", filename);
}

void readMessageFromFile(TreeNode *root, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Check if the line contains Morse code or regular characters
        int isMorseCode = 1;
        for (int i = 0; i < strlen(line); i++)
        {
            if (!strchr(".- ", line[i]))
            {
                isMorseCode = 0;
                break;
            }
        }

        if (isMorseCode)
        {
            printf("Original message (Morse Code): %s\n", line);

            // Convert Morse code to characters
            printf("Characters: ");
            char *token = strtok(line, " ");
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
        else
        {
            printf("Original message: %s\n", line);

            // Convert to Morse code
            printf("Morse Code: ");
            printMorseCode(root, line);
        }
    }

    fclose(file);
}

void user1Menu(TreeNode *root)
{
    int choice;
    while (1)
    {
        menuPengguna1();
        scanf("%d", &choice);
        getchar(); 
s
        switch (choice)
        {
        case 1:
            writeMessageToFile("../user1.txt");
            getchar();
            break;
        case 2:
            readMessageFromFile(root, "../user2.txt");
            getchar();
            break;
        case 0:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void user2Menu(TreeNode *root)
{
    int choice;
    while (1)
    {
        menuPengguna2();
        scanf("%d", &choice);
        getchar(); 

        switch (choice)
        {
        case 1:
            writeMessageToFile("../user2.txt");
            getchar();
            break;
        case 2:
            readMessageFromFile(root, "../user1.txt");
            getchar();
            break;
        case 0:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void feature_encodeMorse(TreeNode *root)
{
    char *input = readInput();
    printf("\nMorse Code:\n");
    printMorseCode(root, input);
    free(input);
}

void feature_decodeMorse(TreeNode *root)
{
    char *input = readInput();
    printf("\nCharacters:\n");
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
    free(input);
}

void printInorder(TreeNode *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        printf("%c ", root->character);
        printInorder(root->right);
    }
}

#endif /* HEADER_H */