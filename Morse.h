#ifndef B8_SANDIMORSE_TREE_H
#define B8_SANDIMORSE_TREE_H

#include "Struktur.h"
#include "StackQueue.h"
#include "Util.h"

morseTree *createmorseTree(info data) {
    morseTree *newmorseTree = (morseTree *) malloc(sizeof(morseTree));
    if (!newmorseTree) {
        printf("Alokasi gagal\n");
        exit(1);
    } else {
        newmorseTree->data = data;
        newmorseTree->leftChild = NULL;
        newmorseTree->rightChild = NULL;
        return newmorseTree;
    }
}

void insertLeft(morseTree **root, info data) {
    morseTree *newmorseTree = createmorseTree(data);
    (*root)->leftChild = newmorseTree;
}

void insertRight(morseTree **root, info data) {
    morseTree *newmorseTree = createmorseTree(data);
    (*root)->rightChild = newmorseTree;
}

void insertCodeMorse(morseTree **root, info data, info codeMorse[]) {
    morseTree *pmorseTree = *root;
    for (int i = 0; i < strlen(codeMorse); i++) {
        if (codeMorse[i] == '.') {
            if (pmorseTree->leftChild == NULL) {
                insertLeft(&pmorseTree, '~');
            }
            pmorseTree = pmorseTree->leftChild;
        } else if (codeMorse[i] == '-') {
            if (pmorseTree->rightChild == NULL) {
                insertRight(&pmorseTree, '~');
            }
            pmorseTree = pmorseTree->rightChild;
        }
    }
    pmorseTree->data = data;
}

void printInOrder(morseTree *root) {
    if (root != NULL) {
        printInOrder(root->leftChild);
        printf("%c", root->data);
        printInOrder(root->rightChild);
    }
}

void initialMorse(morseTree *root) {
    insertCodeMorse(&root, 'E', "."); // .
    insertCodeMorse(&root, 'T', "-"); // -
    insertCodeMorse(&root, 'I', ".."); // ..
    insertCodeMorse(&root, 'A', ".-"); // .-
    insertCodeMorse(&root, 'N', "-."); // -.
    insertCodeMorse(&root, 'M', "--"); // --
    insertCodeMorse(&root, 'S', "..."); // ...
    insertCodeMorse(&root, 'U', "..-"); // ..-
    insertCodeMorse(&root, 'R', ".-."); // .-.
    insertCodeMorse(&root, 'W', ".--"); // .--
    insertCodeMorse(&root, 'D', "-.."); // -..
    insertCodeMorse(&root, 'K', "-.-"); // -.-
    insertCodeMorse(&root, 'G', "--."); // --.
    insertCodeMorse(&root, 'O', "---"); // ---
    insertCodeMorse(&root, 'H', "...."); // ....
    insertCodeMorse(&root, 'V', "...-"); // ...-
    insertCodeMorse(&root, 'F', "..-."); // ..-.
    insertCodeMorse(&root, 'L', ".-.."); // .-..
    insertCodeMorse(&root, 'P', ".--."); // .--.
    insertCodeMorse(&root, 'J', ".---"); // .---
    insertCodeMorse(&root, 'B', "-..."); // -...
    insertCodeMorse(&root, 'X', "-..-"); // -..-
    insertCodeMorse(&root, 'C', "-.-."); // -.-
    insertCodeMorse(&root, 'Y', "-.--"); // -.--
    insertCodeMorse(&root, 'Z', "--.."); // --..
    insertCodeMorse(&root, 'Q', "--.-"); // --.-
    insertCodeMorse(&root, '0', "---."); // ---.
    insertCodeMorse(&root, '5', "....."); // .....
    insertCodeMorse(&root, '4', "....-"); // ....-
    insertCodeMorse(&root, '3', "...--"); // ...--
    insertCodeMorse(&root, '2', "..---"); // ..---
    insertCodeMorse(&root, '1', ".----"); // .----
    insertCodeMorse(&root, '6', "-...."); // -....
    insertCodeMorse(&root, '7', "--..."); // --...
    insertCodeMorse(&root, '8', "---.."); // ---..
    insertCodeMorse(&root, '9', "----."); // ----.
    insertCodeMorse(&root, '\0', ".-..-."); // .-..--
}

void decodeMorse(morseTree *root, char codeMorse[]) {
    // test the function
    int count_strings = 0;
    char **split_strings = split(codeMorse, " ", &count_strings);

    // print out the substrings, which should be each word of the sentence above
    for (int i = 0; i < count_strings; i++) {
//        printf("%s ", split_strings[i]);
        morseTree *pmorseTree = root;
        for (int j = 0; j < strlen(split_strings[i]); j++) {
            if (split_strings[i][j] == '.') {
                pmorseTree = pmorseTree->leftChild;
            } else if (split_strings[i][j] == '-') {
                pmorseTree = pmorseTree->rightChild;
            } else {
                printf("Kode morse salah\n");
                return;
            }
        }
        printf("%c", pmorseTree->data);
    }
    printf("\n");

    // free the dynamically allocated space for each string
    for (int i = 0; i < count_strings; i++)
        free(split_strings[i]);

    // free the dynamically allocated space for the array of pointers to strings
    free(split_strings);
}


// Fungsi untuk mencari path dari nodeTree yang mengandung karakter ke akar
bool findPath(morseTree *root, stack *path, char karakter) {
    if (root == NULL) {
        return false;
    }

    push(path, root);

    if (root->data == karakter) {
        return true;
    }

    if ((root->leftChild && findPath(root->leftChild, path, karakter)) ||
        (root->rightChild && findPath(root->rightChild, path, karakter))) {
        return true;
    }

    pop(path);
    return false;
}

void findPathNode(morseTree *root, stack *stackPathNode, char karakter) {
    if (root == NULL) {
        printf("Pohon kosong\n");
        return;
    }
    findPath(root, (stack *) stackPathNode, karakter);
//    if (findPath(root, (stack *) stackPathNode, karakter)) {
//        printf("Data ditemukan: %c ", karakter);
//    } else {
//        printf("Data tidak ditemukan\n");
//    }


}

void encode(morseTree *root, char text[]) {

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            printf(".-..-.");
        } else {
            stack stackPathNode;
            stackPathNode.top = NULL;
            findPathNode(root, &stackPathNode, toupper(text[i]));
            printf("route : ");
            printdata(stackPathNode.top);
            printf(" morse = ");

            char morseCode[10] = ""; // Morse codes are typically short, max length is 5 for one character
            int morseCodeIndex = 0;

            while (!isEmpty(stackPathNode.top)) {
                morseTree *curr = stackPathNode.top->data;
                pop(&stackPathNode);
                if (stackPathNode.top == NULL) {
                    break;
                }
                morseTree *parent = stackPathNode.top->data;
                if (parent->leftChild == curr) {
                    morseCode[morseCodeIndex++] = '.';
                } else if (parent->rightChild == curr) {
                    morseCode[morseCodeIndex++] = '-';
                }
            }
            printf("%s", morseCode);
        }
        printf("\n");
    }
}


#endif //B8_SANDIMORSE_TREE_H