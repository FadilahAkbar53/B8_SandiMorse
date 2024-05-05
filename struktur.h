//
// Created by ASUS on 2/5/2024.
//

#ifndef B8_SANDIMORSE_STRUKTUR_H
#define B8_SANDIMORSE_STRUKTUR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char info;
typedef struct MorseTree {
    info data;
    struct MorseTree *leftChild;
    struct MorseTree *rightChild;
} morseTree;




#endif //B8_SANDIMORSE_STRUKTUR_H
