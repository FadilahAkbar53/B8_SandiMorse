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
void freeTree(TreeNode *root);
char *readInput();

//Features
void writeMessageToFile(const char *filename);
void readMessageFromFile(TreeNode *root, const char *filename);
void user1Menu(TreeNode *root);
void user2Menu(TreeNode *root);
void fitur_encodeMorse(TreeNode *root);
void fitur_decodeMorse(TreeNode *root);
void printInorder(TreeNode *root);

#endif /* HEADER_H */