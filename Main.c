//
// Created by ASUS on 2/5/2024.
//

#include "Morse.h"


int main(){

    morseTree *root = createmorseTree(' ');

    initialMorse(root);

    getMorse(&root, "J E L A N G A N U G R A H");
    printf("\n");
    getMorsetes(&root, "Q E");

    searchTextFromMorse(root, ".---");//J
    searchTextFromMorse(root, "."); //E
    searchTextFromMorse(root, ".-.."); //L
    searchTextFromMorse(root, ".-"); //A
    searchTextFromMorse(root, "-."); //N
    searchTextFromMorse(root, "--."); //G
    searchTextFromMorse(root, ".-..-."); //spasi
    searchTextFromMorse(root, ".-"); //A
    searchTextFromMorse(root, "-."); //N
    searchTextFromMorse(root, "..-"); //U
    searchTextFromMorse(root, "--."); //G
    searchTextFromMorse(root, ".-."); //R
    searchTextFromMorse(root, ".-"); //A
    searchTextFromMorse(root, "...."); //H

//    printTree(root);

    return 0;
}
