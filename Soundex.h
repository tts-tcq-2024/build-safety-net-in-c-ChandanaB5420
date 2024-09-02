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

