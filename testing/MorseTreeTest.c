#include "../Morse.h"

void testInitialMorseAndSearch(TreeNode *root);
void testDecode(TreeNode *root);
void testEncode(TreeNode *root);

int main(){
    TreeNode *root = NULL;
    initialMorse(&root);

    testInitialMorseAndSearch(root);
    testDecode(root);
    testEncode(root);
}

void testInitialMorseAndSearch(TreeNode *root) {
    char testCharacters[] = {'A','p','.','-', '(', ')', '{', '}'};
    int numTests = sizeof(testCharacters) / sizeof(testCharacters[0]);

    for (int i = 0; i < numTests; i++) {
        TreeNode *result = searchNodeMorse(root, testCharacters[i]);
        if (result != NULL && result->character == testCharacters[i]) {
            printf("Test Passed: Node '%c' found.\n", testCharacters[i]);
        } else if (result == NULL) {
            printf("Test passed: Node '%c' not found.\n", testCharacters[i]);
        }else{
            printf("Test Failed: Unexpected result for character '%c'.\n", testCharacters[i]);
        }
    }

    free(root);
}


// Fungsi untuk menguji fungsi decode
void testDecode(TreeNode *root) {
    const char *testCodes[] = {".-", "-...", "--.-", "-.-.", "..", ".-.-", "----"};
    const char expectedResults[] = {'A', 'B', 'Q', 'C', 'I', '~', '~'};
    int numTests = sizeof(testCodes) / sizeof(testCodes[0]);

    for (int i = 0; i < numTests; i++) {
        char result = decode(root, testCodes[i]);
        if (result == expectedResults[i]) {
            printf("Test Passed: Code '%s' correctly decoded to '%c'.\n", testCodes[i], result);
        } else {
            printf("Test Failed: Code '%s' decoded to '%c' instead of '%c'.\n", testCodes[i], result, expectedResults[i]);
        }
    }
}

void testEncode(TreeNode *root) {
    const char *testInputs[] = {"SOS", "HELLO", "WORLD", "123", "TEST", "INVALID"};
    const char *expectedOutputs[] = {"... --- ...", ".... . .-.. .-.. ---", ".-- --- .-. .-.. -..", ".---- ..--- ...--", "- . ... -", ""};
    int numTests = sizeof(testInputs) / sizeof(testInputs[0]);

    for (int i = 0; i < numTests; i++) {
        char *result = encode(root, testInputs[i]);
        if (strcmp(result, expectedOutputs[i]) == 0) {
            printf("Test Passed: Input '%s' correctly encoded to '%s'.\n", testInputs[i], result);
        } else {
            printf("Test Failed: Input '%s' encoded to '%s' instead of '%s'.\n", testInputs[i], result, expectedOutputs[i]);
        }
        free(result);
    }
}




