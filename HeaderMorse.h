#ifndef HEADER_H
#define HEADER_H

#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct TreeNode
{
    char character;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

// Function Morse.h
TreeNode *createTreeNode(char character, TreeNode *parent);
void insertCodeMorse(TreeNode **root, const char *code, char character);
void initialMorse(TreeNode **root);
TreeNode* searchNodeMorse(TreeNode *root, char character);
void findMorseCode(TreeNode *root, char character, char *buffer, int depth);
void printMorseCode(TreeNode *root, const char *input);
char decode(TreeNode *root, const char *code);
char *encode(TreeNode *root,const char *input);
void freeTree(TreeNode *root);

// Function Feature.h
char *readInput();
void writeMessageToFile(const char *filename);
void readMessageFromFile(TreeNode *root, const char *filename);
void user1Menu(TreeNode *root);
void user2Menu(TreeNode *root);
void fitur_encodeMorse(TreeNode *root);
void fitur_decodeMorse(TreeNode *root);
void printInorder(TreeNode *root);
void hierarchyRoot(TreeNode *root, char target, int level, bool *found);
void findAndhierarchyRoot(TreeNode *root, char target);
void displayHierarchy(TreeNode *root);
int findPathToRoot(TreeNode *node, char *path, int *sidePath);
void findPath(TreeNode *root, char start, char end);
char* fitur_getUser(bool showUser);

// Function Tampilan.h
void menuUtama();
void menuTerjemah();
void menuHirarki();
void menuPercakapan();
void menuPengguna1();
void menuPengguna2();
void menuPilihUserOnline();
void menuloginUser();
void menuPenggunaOnline(char* user);

#endif /* HEADER_H */