#ifndef SOUNDEX_H
#define SOUNDEX_H

char getSoundexCode(char c);
void generateSoundex(const char *name, char *soundex);


 
#include "Soundex.h"
#include <ctype.h>

// Precomputed mapping from characters to Soundex codes
static const char codeMap[] = "000000000000012301200400500600";

// Pure function to get the Soundex code for a given character
char getSoundexCode(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ? codeMap[toupper(c) - 'A'] : '0';
}

// Pure function to get the Soundex code for a substring of the name
void getSoundexCodeForName(const char *name, char *soundex, int *index, char previousCode) {
    if (name[0] == '\0' || *index >= 4) {
        return;
    }

    char currentCode = getSoundexCode(name[0]);
    if (currentCode != '0' && currentCode != previousCode) {
        soundex[*index] = currentCode;
        (*index)++;
    }

    getSoundexCodeForName(name + 1, soundex, index, currentCode);
}

// Pure function to generate the Soundex code
void generateSoundex(const char *name, char *soundex) {
    if (name[0] == '\0') {
        // Handle the case when the input name is empty
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(name[0]); // Start with the first character
    soundex[1] = soundex[2] = soundex[3] = '0'; // Pre-fill remaining positions
    int index = 1; // Start filling Soundex from index 1

    getSoundexCodeForName(name + 1, soundex, &index, '0');

    soundex[4] = '\0'; // Null-terminate the Soundex code
}

#endif // SOUNDEX_H
