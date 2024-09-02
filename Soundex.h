#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

#include <ctype.h>

char getSoundexCode(char c) {
    static const char soundexMap[26] = {
        '0', // A
        '1', // B
        '2', // C
        '3', // D
        '0', // E
        '1', // F
        '2', // G
        '0', // H
        '0', // I
        '1', // J
        '2', // K
        '0', // L
        '5', // M
        '5', // N
        '0', // O
        '2', // P
        '0', // Q
        '0', // R
        '0', // S
        '3', // T
        '0', // U
        '1', // V
        '0', // W
        '0', // X
        '2', // Y
        '2'  // Z
    };

    // Convert character to uppercase
    c = toupper(c);

    // Check if character is within 'A' to 'Z'
    if (c >= 'A' && c <= 'Z') {
        return soundexMap[c - 'A'];
    }

    return '0'; // For non-alphabetic characters
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
