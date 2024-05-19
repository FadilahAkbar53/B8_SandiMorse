#ifndef MORSE_H
#define MORSE_H

#include "HeaderMorse.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

TreeNode *createTreeNode(char character, TreeNode *parent) {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->character = character;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;  // Inisialisasi parent pointer
    return newNode;
}

void insertCodeMorse(TreeNode **root, const char *code, char character)
{
    if (*root == NULL) {
        *root = createTreeNode('@', NULL);
    }

    TreeNode *current = *root;
    while (*code) {
        if (*code == '.') {
            if (current->left == NULL) {
                current->left = createTreeNode('~', current);
            }
            current = current->left;
        } else if (*code == '-') {
            if (current->right == NULL) {
                current->right = createTreeNode('~', current);
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

TreeNode* searchNodeMorse(TreeNode *root, char character) {
    if (root == NULL) {
        return NULL;
    }
    if (root->character == character) {
        return root;
    }
    TreeNode *leftResult = searchNodeMorse(root->left, character);
    if (leftResult != NULL) {
        return leftResult;
    }
    return searchNodeMorse(root->right, character);
}

char decode(TreeNode *root, const char *code)
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



char *encode(TreeNode *root, const char *input) {
    if (input == NULL || *input == '\0') {
        return NULL;
    }

    size_t resultSize = 1;
    char *result = (char*)malloc(resultSize * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    result[0] = '\0';

    while (*input) {
        stack codeStack;
        codeStack.top = NULL;

        TreeNode *current = searchNodeMorse(root, toupper(*input));
        if (current == NULL) {
            input++;
            continue; // skip characters that are not found in the tree
        }

        while (current->parent != NULL) {
            TreeNode *parent = current->parent;
            if (current == parent->left) {
                push(&codeStack, '.');
            } else if (current == parent->right) {
                push(&codeStack, '-');
            }
            current = parent;
        }

        char *morseCode = linkedListToString(codeStack.top);

        while (codeStack.top != NULL) {
            stack *temp = (stack *) codeStack.top;
            codeStack.top = codeStack.top->next;
            free(temp);
        }

        if (morseCode != NULL) {
            resultSize += strlen(morseCode) + 1;
            result = (char*)realloc(result, resultSize * sizeof(char));
            if (result == NULL) {
                printf("Memory allocation failed\n");
                return NULL;
            }
            strcat(result, morseCode);
            strcat(result, " ");
            free(morseCode);
        }
        input++;
    }

    result[resultSize - 2] = '\0'; // Remove the trailing space

    return result;
}


void freeTree(TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        freeTree(root->parent);
        free(root);
    }
}

char *readInput()
{
    char *input = malloc(1024);
    if (!input)
    {
        printf("Memory allocation error.\n");
        exit(1);
    }
    printf("\nEnter input (end with Enter): ");
    if (fgets(input, 1024, stdin) != NULL)
    {
        input[strcspn(input, "\n")] = '\0'; // remove newline character
    }
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
    encode(root, input);
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
        encode(root, line);
    }

    fclose(file);
}

void fitur_encodeMorse(TreeNode *root) {
    char *input = readInput();
    if (input == NULL) {
        return;
    }

    printf("\nMorse Code:\n");
    char *morseCode = encode(root, input);
    if (morseCode != NULL) {
        printf("%s\n", morseCode);
        free(morseCode);
    }
    free(input);
}

void fitur_decodeMorse(TreeNode *root)
{
    char *input = readInput();
    printf("\nCharacters:\n");
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        char result = decode(root, token);
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