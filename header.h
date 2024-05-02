#ifndef header_H
#define header_H

// Define the structure for the tree node
typedef struct TreeNode {
    char label;
    char* morseCode;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Global pointer variable
extern TreeNode *root;

// Function to create a new tree node
TreeNode* createNewTreeNode(char label, char* morseCode);

// Recursive function to insert a new node
void insert(TreeNode* node, char label, char* morseCode);

// Recursive function to insert alphabet
void insertAlphabet(TreeNode* node);

// Recursive function to encode a character to Morse code
char* encodeMorse(TreeNode* node, char c);

// Function to encode a character to Morse code
char* encodeCharacter(char c);

#endif /* HEADER_H */
