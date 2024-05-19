#ifndef HEADER_H
#define HEADER_H

#include "Stack.h"

typedef struct TreeNode
{
    char character;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

TreeNode *createTreeNode(char character, TreeNode *parent);
void insertCodeMorse(TreeNode **root, const char *code, char character);
void initialMorse(TreeNode **root);
TreeNode* searchNodeMorse(TreeNode *root, char character);
char decode(TreeNode *root, const char *code);
char *encode(TreeNode *root,const char *input);
void freeTree(TreeNode *root);
char *readInput();

void fitur_encodeMorse(TreeNode *root);
void fitur_decodeMorse(TreeNode *root);
void printInorder(TreeNode *root);

#endif /* HEADER_H */