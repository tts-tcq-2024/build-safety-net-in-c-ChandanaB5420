#ifndef SOUNDEX_H
#define SOUNDEX_H

char getSoundexCode(char c);
void generateSoundex(const char *name, char *soundex);

#endif // SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Maps a character to its Soundex code
char getSoundexCode(char c) {
    static const char codeMap[256] = {
        ['A'] = '0', ['E'] = '0', ['I'] = '0', ['O'] = '0', ['U'] = '0',
        ['H'] = '0', ['W'] = '0', ['Y'] = '0',
        ['B'] = '1', ['F'] = '1', ['P'] = '1', ['V'] = '1',
        ['C'] = '2', ['G'] = '2', ['J'] = '2', ['K'] = '2', ['Q'] = '2', ['S'] = '2', ['X'] = '2', ['Z'] = '2',
        ['D'] = '3', ['T'] = '3',
        ['L'] = '4',
        ['M'] = '5', ['N'] = '5',
        ['R'] = '6'
    };
    return codeMap[toupper((unsigned char)c)];
}

// Recursive function to fill the Soundex code
void generateSoundexRecursive(const char *name, char *soundex, char previousCode, int sIndex) {
    if (*name == '\0' || sIndex >= 4) {
        // End of string or Soundex array is full, fill with '0' if necessary
        while (sIndex < 4) {
            soundex[sIndex++] = '0';
        }
        soundex[4] = '\0'; // Null-terminate the result
        return;
    }

    char currentCode = getSoundexCode(*name);
    if (currentCode != '0' && currentCode != previousCode) {
        soundex[sIndex++] = currentCode;
    }

    // Recurse with the next character
    generateSoundexRecursive(name + 1, soundex, currentCode, sIndex);
}

// Generate Soundex code from the given name
void generateSoundex(const char *name, char *soundex) {
    if (*name == '\0') {
        // Handle the case when the input name is empty
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(*name); // Start with the first character
    generateSoundexRecursive(name + 1, soundex, getSoundexCode(*name), 1);
}
