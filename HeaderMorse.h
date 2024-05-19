#ifndef HEADER_H
#define HEADER_H

typedef struct TreeNode
{
    char character;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createMorseTree(char character);
void insertCodeMorse(TreeNode **root, const char *code, char character);
void initialMorse(TreeNode **root);
char searchMorseCode(TreeNode *root, const char *code);
void findMorseCode(TreeNode *root, char character, char *buffer, int depth);
void printMorseCode(TreeNode *root, const char *input);
void encodeMorse(TreeNode *root, const char *input, char *output);
void decodeMorse(TreeNode *root, const char *input, char *output);
void freeTree(TreeNode *root);
char *readInput();
void fitur_encodeMorse(TreeNode *root);
void fitur_decodeMorse(TreeNode *root);
void printInorder(TreeNode *root);

#endif /* HEADER_H */