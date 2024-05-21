
#ifndef B8_SANDIMORSE_FEATURE_H
#define B8_SANDIMORSE_FEATURE_H

#include "Morse.h"

char *readInput() {
    char *input = malloc(1024);
    if (!input) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    printf("\nEnter input (end with Enter): ");
    if (fgets(input, 1024, stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0'; // remove newline character
    }
    return input;
}

void writeMessageToFile(const char *filename) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    char *input = readInput();
    fprintf(file, "\n%s", input);

    fclose(file);
    free(input);
    printf("Message written to file %s.\n", filename);
}

void readMessageFromFile(TreeNode *root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Check if the line contains Morse code or regular characters
        int isMorseCode = 1;
        for (int i = 0; i < strlen(line); i++) {
            if (!strchr(".- ", line[i])) {
                isMorseCode = 0;
                break;
            }
        }

        if (isMorseCode) {
            printf("Original message (Morse Code): %s\n", line);

            // Convert Morse code to characters
            printf("Characters: ");
            char *token = strtok(line, " ");
            while (token != NULL) {
                char result = decode(root, token);
                if (result != '\0') {
                    printf("%c", result);
                } else {
                    printf("?");
                }
                token = strtok(NULL, " ");
            }
            printf("\n");
        } else {
            printf("Original message: %s\n", line);

            // Convert to Morse code
            printf("Morse Code: ");
            printMorseCode(root, line);
        }
    }

    fclose(file);
}

void user1Menu(TreeNode *root) {
    int choice;
    while (1) {
        menuPengguna1();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
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

void user2Menu(TreeNode *root) {
    int choice;
    while (1) {
        menuPengguna2();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
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

void fitur_decodeMorse(TreeNode *root) {
    char *input = readInput();
    printf("\nCharacters:\n");
    char *token = strtok(input, " ");
    while (token != NULL) {
        char result = decode(root, token);
        if (result != '\0') {
            printf("%c", result);
        } else {
            printf("?");
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
    free(input);
}

void printInorder(TreeNode *root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%c ", root->character);
        printInorder(root->right);
    }
}

// function to print hierarchy from root to the target character
void hierarchyRoot(TreeNode *root, char target, int level, bool *found) {
    if (root == NULL) {
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
    if (root->character == target) {
        *found = true; // Set found to true to stop further printing
        return;
    }

    // Traverse the right subtree last
    hierarchyRoot(root->right, target, level + 1, found);
}

void findAndhierarchyRoot(TreeNode *root, char target) {
    bool found = false;
    hierarchyRoot(root, target, 0, &found);
    if (!found) {
        printf("Character '%c' not found in the Morse tree.\n", target);
    }
    getchar();
}

// Function to prompt user for a character and display its hierarchy
void displayHierarchy(TreeNode *root) {
    char inputChar;
    printf("Enter the character to find its hierarchy: ");
    scanf(" %c", &inputChar);

    printf("Hierarchy for character '%c':\n", inputChar);
    findAndhierarchyRoot(root, toupper(inputChar));
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
    TreeNode *startNode = searchNodeMorse(root, start);
    TreeNode *endNode = searchNodeMorse(root, end);

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

#endif //B8_SANDIMORSE_FEATURE_H
