#ifndef HEADER_H
#define HEADER_H

typedef struct TreeNode
{
    char character;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

TreeNode *createNode(char character, TreeNode *parent);
void insertCodeMorse(TreeNode **root, const char *code, char character);
void initialMorse(TreeNode **root);
TreeNode* searchNodeMorse(TreeNode *root, char character);
char searchMorseCode(TreeNode *root, const char *code);
void findMorseCode(TreeNode *root, char character, char *buffer, int depth);
void printMorseCode(TreeNode *root, const char *input);
void freeTree(TreeNode *root);
char *readInput();
void fitur_encodeMorse(TreeNode *root);
void fitur_decodeMorse(TreeNode *root);
void printInorder(TreeNode *root);

#endif /* HEADER_H */