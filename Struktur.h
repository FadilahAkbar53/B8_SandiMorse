//
// Created by ASUS on 13/5/2024.
//

#ifndef B8_SANDIMORSE_STRUKTUR_H
#define B8_SANDIMORSE_STRUKTUR_H

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char info;
typedef struct MorseTree {
    info data;
    struct MorseTree *leftChild;
    struct MorseTree *rightChild;
} morseTree;

typedef struct Node{
    morseTree *data;
    struct Node *next;
}nodeTree;

typedef struct Stack {
    nodeTree *top;
} stack;

typedef struct QueueChar {
    info data;
    struct QueueChar *next;
} queueChar;

#endif //B8_SANDIMORSE_STRUKTUR_H
