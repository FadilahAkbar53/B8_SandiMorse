#ifndef MORSE_H
#define MORSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct TreeNode
{
    char character;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent; // Add a parent pointer
} TreeNode;

TreeNode *createMorseTree(char character, TreeNode *parent)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->character = character;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent; // Set the parent
    return newNode;
}

void insertCodeMorse(TreeNode **root, const char *code, char character)
{
    if (*root == NULL)
    {
        *root = createMorseTree('\0', NULL);
    }

    TreeNode *current = *root;
    while (*code)
    {
        if (*code == '.')
        {
            if (current->left == NULL)
            {
                current->left = createMorseTree('\0', current);
            }
            current = current->left;
        }
        else if (*code == '-')
        {
            if (current->right == NULL)
            {
                current->right = createMorseTree('\0', current);
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

    // Add Morse code for symbols
    insertCodeMorse(root, "..--..", '?');
    insertCodeMorse(root, "-.-.--", '!');
    insertCodeMorse(root, "---...", ':');
    insertCodeMorse(root, "-...-", '=');
    insertCodeMorse(root, "-..-.", '/');
    insertCodeMorse(root, "-.--.", '(');
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

void printTree(TreeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    printTree(root->left, level + 1);  // Visit left subtree first
    printf("%c", root->character);   // Visit the root node
    printTree(root->right, level + 1); // Visit right subtree last
}

// New function to print hierarchy from root to the target character
void hierarchyRoot(TreeNode *root, char target, int level, bool *found)
{
    if (root == NULL)
    {
        return;
    }

    // Traverse the left subtree first
    hierarchyRoot(root->left, target, level + 1, found);

    // Print the current node's character
    if (!*found) // Only print if target has not been found yet
    {
        printf("%c", root->character);
    }

    // Check if the current node is the target
    if (root->character == target)
    {
        *found = true; // Set found to true to stop further printing
        return;
    }

    // Traverse the right subtree last
    hierarchyRoot(root->right, target, level + 1, found);
}

void findAndhierarchyRoot(TreeNode *root, char target)
{
    bool found = false;
    hierarchyRoot(root, target, 0, &found);
    if (!found)
    {
        printf("Character '%c' not found in the Morse tree.\n", target);
    }
    getchar();
}

// Function to prompt user for a character and display its hierarchy
void displayHierarchy(TreeNode *root)
{
    char inputChar;
    printf("Enter the character to find its hierarchy: ");
    scanf(" %c", &inputChar);

    printf("Hierarchy for character '%c':\n", inputChar);
    findAndhierarchyRoot(root, toupper(inputChar));
}

// Function to find the node with a given character
TreeNode *findNode(TreeNode *root, char target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->character == target) {
        return root;
    }
    TreeNode *leftResult = findNode(root->left, target);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(root->right, target);
}

// Function to find the path from a node to the root
int findPathToRoot(TreeNode *node, char *path, int *sidePath) {
    int length = 0;
    while (node != NULL) {
        path[length] = node->character;
        sidePath[length] = (node->parent && node->parent->right == node) ? 1 : 0; // right:1, left:0
        node = node->parent;
        length++;
    }
    return length;
}

// Function to find the path between two characters
void findPath(TreeNode *root, char start, char end) {
    TreeNode *startNode = findNode(root, start);
    TreeNode *endNode = findNode(root, end);

    if (startNode == NULL) {
        printf("Start character '%c' not found in the Morse tree.\n", start);
        return;
    }

    if (endNode == NULL) {
        printf("End character '%c' not found in the Morse tree.\n", end);
        return;
    }

    char pathStart[100], pathEnd[100];
    int sidePathStart[100], sidePathEnd[100];
    int pathStartLen = findPathToRoot(startNode, pathStart, sidePathStart);
    int pathEndLen = findPathToRoot(endNode, pathEnd, sidePathEnd);

    // Find the lowest common ancestor (LCA)
    int i = pathStartLen - 1;
    int j = pathEndLen - 1;
    while (i >= 0 && j >= 0 && pathStart[i] == pathEnd[j]) {
        i--;
        j--;
    }

    // Print the path from the start character to the LCA (excluding the LCA)
    printf("Path from '%c' to '%c': ", start, end);
    for (int k = 0; k <= i; k++) {
        if (sidePathStart[k] == 0 || k == 0) { // Print only if it's a left child or the first character
            printf("%c ", pathStart[k]);
        }
    }

    // Print the path from the LCA to the end character
    for (int k = j + 1; k >= 0; k--) {
        printf("%c ", pathEnd[k]);
    }
    printf("\n");
    getchar();
}

#endif /* HEADER_H */