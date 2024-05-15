//
// Created by ASUS on 2/5/2024.
//

#include "Morse.h"


int main(){

    morseTree *root = createmorseTree('~');

    initialMorse(root);

//    printInOrder(root);
//
//    printf("\n");
//
    encode(root, "JELANG Anugrah");


    decodeMorse(root, ".--- . .-.. .- -. --. .-..-. .- -. ..- --. .-. .- ....");



    return 0;
}
