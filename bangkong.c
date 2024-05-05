//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "header.h"
//
//// Global pointer variable
//TreeNode *root = NULL;
//
//// Function to create a new tree node
//TreeNode* createNewTreeNode(char label, char* morseCode) {
//    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//    newNode->label = label;
//    newNode->morseCode = morseCode;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//// Recursive function to insert a new node
//void insert(TreeNode* node, char label, char* morseCode) {
//    if (node == NULL) {
//        printf("\nBuat tree terlebih dahulu!!\n");
//        return;
//    }
//
//    if (label < node->label) {
//        if (node->left == NULL)
//            node->left = createNewTreeNode(label, morseCode);
//        else
//            insert(node->left, label, morseCode);
//    } else if (label > node->label) {
//        if (node->right == NULL)
//            node->right = createNewTreeNode(label, morseCode);
//        else
//            insert(node->right, label, morseCode);
//    } else {
//        printf("\nNode dengan label %c sudah ada!!\n", label);
//    }
//}
//
//// Recursive function to insert alphabet
//void insertAlphabet(TreeNode* node) {
//    insert(node, 'A', ".-");
//    insert(node, 'B', "-...");
//    insert(node, 'C', "-.-.");
//    insert(node, 'D', "-..");
//    insert(node, 'E', ".");
//    insert(node, 'F', "..-.");
//    insert(node, 'G', "--.");
//    insert(node, 'H', "....");
//    insert(node, 'I', "..");
//    insert(node, 'J', ".---");
//    insert(node, 'K', "-.-");
//    insert(node, 'L', ".-..");
//    insert(node, 'M', "--");
//    insert(node, 'N', "-.");
//    insert(node, 'O', "---");
//    insert(node, 'P', ".--.");
//    insert(node, 'Q', "--.-");
//    insert(node, 'R', ".-.");
//    insert(node, 'S', "...");
//    insert(node, 'T', "-");
//    insert(node, 'U', "..-");
//    insert(node, 'V', "...-");
//    insert(node, 'W', ".--");
//    insert(node, 'X', "-..-");
//    insert(node, 'Y', "-.--");
//    insert(node, 'Z', "--..");
//}
//
//// Recursive function to encode a character to Morse code
//char* encodeMorse(TreeNode* node, char c) {
//    if (node == NULL)
//        return ""; // Character not found in the tree
//
//    if (node->label == c)
//        return node->morseCode; // Character found, return its Morse code
//
//    char* leftResult = encodeMorse(node->left, c);
//    if (strcmp(leftResult, "") != 0)
//        return leftResult; // If found on the left side, return its Morse code
//
//    char* rightResult = encodeMorse(node->right, c);
//    if (strcmp(rightResult, "") != 0)
//        return rightResult; // If found on the right side, return its Morse code
//
//    return ""; // Character not found in the tree
//}
//
//// Function to encode a character to Morse code
//char* encodeCharacter(char c) {
//    if (root == NULL) {
//        printf("\nBuat tree terlebih dahulu!!\n");
//        return "";
//    }
//
//    if (c >= 'A' && c <= 'Z')
//        return encodeMorse(root, c);
//    else if (c >= 'a' && c <= 'z')
//        return encodeMorse(root, c - ('a' - 'A')); // Convert lowercase to uppercase
//    else
//        return ""; // Invalid character
//}
//
//// Fungsi untuk mencari karakter berdasarkan sandi Morse
//char decodeMorse(TreeNode* node, char* morse) {
//    if (node == NULL)
//        return '\0'; // Node tidak ditemukan
//
//    if (strcmp(node->morseCode, morse) == 0)
//        return node->label; // Sandi Morse cocok dengan label node
//
//    char result = decodeMorse(node->left, morse); // Cari di sebelah kiri
//    if (result != '\0')
//        return result;
//
//    result = decodeMorse(node->right, morse); // Cari di sebelah kanan
//    if (result != '\0')
//        return result;
//
//    return '\0'; // Tidak ada karakter yang sesuai
//}
//
//// Fungsi untuk mengonversi sandi Morse menjadi karakter atau kalimat
//char* decodeMorseCode(TreeNode* root, char* morseCode) {
//    if (root == NULL) {
//        printf("\nBuat tree terlebih dahulu!!\n");
//        return "";
//    }
//
//    char* token = strtok(morseCode, " "); // Pisahkan sandi Morse berdasarkan spasi
//    char* result = (char*)malloc(strlen(morseCode) * sizeof(char)); // Alokasikan memori untuk hasil
//    int index = 0;
//
//    while (token != NULL) {
//        char decodedChar = decodeMorse(root, token);
//        if (decodedChar != '\0') {
//            result[index++] = decodedChar; // Tambahkan karakter yang ditemukan ke hasil
//        } else {
//            // Jika sandi Morse tidak ditemukan, tambahkan spasi
//            result[index++] = ' ';
//        }
//        token = strtok(NULL, " "); // Lanjutkan dengan token berikutnya
//    }
//
//    result[index] = '\0'; // Tambahkan null-terminator pada akhir string
//    return result;
//}
