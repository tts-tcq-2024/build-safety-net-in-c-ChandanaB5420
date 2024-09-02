#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Maps a character to its Soundex code
char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

// Recursive helper function to process the name and generate the Soundex code
void generateSoundexRecursive(const char *name, char *soundex, int sIndex, char previousCode) {
    if (sIndex >= 4 || name[0] == '\0') {
        // Base case: stop recursion if we have filled the Soundex code or reached the end of the name
        while (sIndex < 4) soundex[sIndex++] = '0';
        soundex[4] = '\0'; // Null-terminate the result
        return;
    }

    char code = getSoundexCode(name[0]);
    if (code != '0' && code != previousCode) {
        soundex[sIndex] = code;
        generateSoundexRecursive(name + 1, soundex, sIndex + 1, code);
    } else {
        generateSoundexRecursive(name + 1, soundex, sIndex, previousCode);
    }
}

// Generates the Soundex code from a given name
void generateSoundex(const char *name, char *soundex) {
    if (name[0] == '\0') {
        soundex[0] = '\0'; // Handle empty name
        return;
    }

    soundex[0] = toupper(name[0]); // Start with the first character
    generateSoundexRecursive(name + 1, soundex, 1, getSoundexCode(name[0]));
}
