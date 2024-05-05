//
// Created by ASUS on 2/5/2024.
//

#ifndef B8_SANDIMORSE_TREE_H
#define B8_SANDIMORSE_TREE_H

#include "Struktur.h"
#include "lib/Stack.h"
#include <ctype.h>

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
                insertLeft(&pmorseTree, ' ');
            }
            pmorseTree = pmorseTree->leftChild;
        } else if (codeMorse[i] == '-') {
            if (pmorseTree->rightChild == NULL) {
                insertRight(&pmorseTree, ' ');
            }
            pmorseTree = pmorseTree->rightChild;
        }
    }
    pmorseTree->data = data;
}

void printTree(morseTree *root) {
    if (root != NULL) {
        printf("%c", root->data); // Cetak data dari simpul saat ini

        if (root->leftChild != NULL || root->rightChild != NULL) {
            printf("("); // Cetak tanda kurung pembuka jika simpul saat ini memiliki anak

            if (root->leftChild != NULL)
                printTree(root->leftChild); // Cetak anak kiri jika ada

            printf(","); // Cetak koma sebagai pemisah antara anak kiri dan kanan

            if (root->rightChild != NULL)
                printTree(root->rightChild); // Cetak anak kanan jika ada

            printf(")"); // Cetak tanda kurung penutup
        }
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

void searchTextFromMorse(morseTree *root, info codeMorse[]) {
    morseTree *pmorseTree = root;
    for (int i = 0; i < strlen(codeMorse); i++) {
        if (codeMorse[i] == '.') {
            pmorseTree = pmorseTree->leftChild;
        } else if (codeMorse[i] == '-') {
            pmorseTree = pmorseTree->rightChild;
        }
    }
    printf("%c", pmorseTree->data);
}

// Fungsi untuk mencari kode Morse dari sebuah karakter dalam pohon Morse
int getMorseCode(morseTree *morseTree, char character, list *codeStack) {
    if (morseTree == NULL)
        return 0;

    if (morseTree->data == character)
        return 1;

    if (getMorseCode(morseTree->leftChild, character, codeStack)) {
        push(&codeStack->head, &codeStack->tail, '.');
        return 1;
    }

    if (getMorseCode(morseTree->rightChild, character, codeStack)) {
        push(&codeStack->head, &codeStack->tail, '-');
        return 1;
    }

    return 0;
}

// Fungsi untuk mencari kode Morse dari sebuah karakter dalam pohon Morse
int getMorseCodetes(morseTree *morseTree, char character, char *code) {
    if (morseTree == NULL)
        return 0;

    if (morseTree->data == character)
        return 1;

    if (getMorseCodetes(morseTree->leftChild, character, code)) {
        strcat(code, ".");
        return 1;
    }

    if (getMorseCodetes(morseTree->rightChild, character, code)) {
        strcat(code, "-");
        return 1;
    }

    return 0;
}

void getMorsetes(morseTree **root, char *morse) {

    char morseCode[100];
    morseCode[0] = '\0';
    for (int i = 0; i < strlen(morse); i++) {
        char code[100] = "";
        getMorseCodetes(*root, toupper(morse[i]), code);
        strcat(morseCode, code);
        if (morse[i + 1] != '\0' && morse[i + 1] != ' ') {
//            strcat(morseCode, ".-..--"); // Tambahkan spasi setelah setiap karakter Morse, kecuali jika karakter berikutnya adalah spasi
            strcat(morseCode, " "); // Tambahkan spasi setelah setiap karakter Morse, kecuali jika karakter berikutnya adalah spasi
        }
    }
    printf("%s\n", morseCode);
}

void getMorse(morseTree **root, char *morse) {

    list codeStack;
    codeStack.head = NULL;
    codeStack.tail = NULL;


    for (int i = 0; i < strlen(morse); i++) {
        if (morse[i] == ' ') {
            while (!isEmpty(codeStack.head)) {
                printf("%c", pop(&codeStack.head));
            }
//            printf(".-..--");
            printf(" ");
        } else {
            getMorseCode(*root, toupper(morse[i]), &codeStack);
        }
    }
    while (!isEmpty(codeStack.head)) {
        printf("%c", pop(&codeStack.head));
    }
    printf("\n");

}

#endif //B8_SANDIMORSE_TREE_H
