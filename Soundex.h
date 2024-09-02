#ifndef SOUNDEX_H
#define SOUNDEX_H

char getSoundexCode(char c);
void generateSoundex(const char *name, char *soundex);
 
#include "Soundex.h"
#include <ctype.h>


static const char codeMap[] = "000000000000012301200400500600";

char getSoundexCode(char c) {
    char upperChar = toupper(c);
    if (upperChar < 'A' || upperChar > 'Z') {
        return '0'; // Non-alphabetic character
    }
    return codeMap[upperChar - 'A'];
}

void getSoundexCodeForName(const char *name, char *soundex, int *index, char previousCode) {
    while (*name != '\0' && *index < 4) {
        char currentCode = getSoundexCode(*name);

        if (currentCode != '0' && currentCode != previousCode) {
            soundex[*index] = currentCode;
            (*index)++;
            previousCode = currentCode; // Update previousCode to the currentCode used
        }

        name++; // Move to the next character
    }
}


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
