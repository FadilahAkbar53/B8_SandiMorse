#ifndef MORSE_H
#define MORSE_H

#include "HeaderMorse.h"

TreeNode *createTreeNode(char character, TreeNode *parent) {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->character = character;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;  // Initialize parent pointer
    return newNode;
}

void insertCodeMorse(TreeNode **root, const char *code, char character) {
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

void initialMorse(TreeNode **root) {
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

    // Add Morse codes for space and symbols
    insertCodeMorse(root, ".-..-.", ' ');
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

void findMorseCode(TreeNode *root, char character, char *buffer, int depth) {
    if (root == NULL) {
        return;
    }
    if (root->character == character) {
        buffer[depth] = '\0';
        printf("%s ", buffer);
        return;
    }
    buffer[depth] = '.';
    findMorseCode(root->left, character, buffer, depth + 1);
    buffer[depth] = '-';
    findMorseCode(root->right, character, buffer, depth + 1);
}

void printMorseCode(TreeNode *root, const char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            printf(".-..-. ");
        } else {
            char buffer[100];
            findMorseCode(root, toupper(input[i]), buffer, 0);
        }
    }
    printf("\n");
}

char decode(TreeNode *root, const char *code) {
    TreeNode *current = root;
    while (*code && current != NULL) {
        if (*code == '.') {
            current = current->left;
        } else if (*code == '-') {
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

void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}



#endif /* HEADER_H */
