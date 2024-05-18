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

    // Add Morse code for simbol
    insertCodeMorse(root, "..--..", '?');
    insertCodeMorse(root, "-.-.--", '!');
    insertCodeMorse(root, "---...", ':');
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

void encodeMorse(TreeNode *root, const char *input, char *output)
{
    output[0] = '\0';
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            strcat(output, ".-..-. ");
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

void decodeMorse(TreeNode *root, const char *input, char *output)
{
    output[0] = '\0';

    char *token = strtok((char *)input, " ");
    while (token != NULL)
    {
        char result = searchMorseCode(root, token);
        if (result != '\0')
        {
            strncat(output, &result, 1);
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

void writeMessageToFile(TreeNode *root)
{
    FILE *file = fopen("C:/Users/Fadilah Akbar/OneDrive/Dokumen/Kuliah/Semester 2/Struktur Data dan Algortima/SandiMorse2/test1/user1.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    char *input = readInput();
    fprintf(file, "\n%s", input);

    fclose(file);
    free(input);
    printf("Message written to file user1.txt.\n");
}

void readMessageFromFileAndConvert(TreeNode *root)
{
    FILE *file = fopen("C:/Users/Fadilah Akbar/OneDrive/Dokumen/Kuliah/Semester 2/Struktur Data dan Algortima/SandiMorse2/test1/user1.txt", "r");
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
        printf("Original message: %s\n", line);

        // Convert to Morse code
        printf("Morse Code: ");
        printMorseCode(root, line);
    }

    fclose(file);
}

void fitur_encodeMorse(TreeNode *root)
{
    char *input = readInput();
    printf("\nMorse Code:\n");
    printMorseCode(root, input);
    free(input);
}

void fitur_decodeMorse(TreeNode *root)
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