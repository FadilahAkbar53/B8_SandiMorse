//
// Created by ASUS on 2/5/2024.
//

#include "Morse.h"


int main(){

    morseTree *root = createmorseTree('~');

    initialMorse(root);
    printf("print in order : ");
    printInOrder(root);
    printf("\nprint encoded : ");
    encode(root, "JELANG ANUGRAH");
    printf("\nprint decoded : ");
    decodeMorse(root, ".--- . .-.. .- -. --. .-..-. .- -. ..- --. .-. .- ....");



    return 0;
}
