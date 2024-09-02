#include <stdio.h>
#include <string.h>
#include "Soundex.h"


int testSoundex(const char *name, const char *expected) {
    char soundex[5];
    generateSoundex(name, soundex);
    return strcmp(soundex, expected) == 0;
}


void printTestResult(const char *name, const char *expected) {
    if (testSoundex(name, expected)) {
        printf("Test passed for %s: %s\n", name, expected);
    } else {
        char soundex[5];
        generateSoundex(name, soundex);
        printf("Test failed for %s: expected %s, got %s\n", name, expected, soundex);
    }
}

int main() {
   
    printTestResult("Smith", "S530");
    printTestResult("Smyth", "S530");
    printTestResult("Robert", "R163");
    printTestResult("Rupert", "R163");
    printTestResult("Ashcraft", "A261");
    printTestResult("Ashcroft", "A261");

    return 0;
}
