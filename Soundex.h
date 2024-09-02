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
    if (name == NULL || soundex == NULL) {
        return;
    }

    // Initialize the Soundex code with the first character
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    // Iterate over the name and process Soundex codes
    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        // Only add the code if it's not '0' and differs from the previous code
        if (code != '0' && (sIndex == 1 || code != soundex[sIndex - 1])) {
            soundex[sIndex++] = code;
        }
    }

    // Ensure the Soundex code is exactly 4 characters long
    if (sIndex < 4) {
        memset(soundex + sIndex, '0', 4 - sIndex);
    }

    soundex[4] = '\0'; // Null-terminate the Soundex string
}

#endif // SOUNDEX_H

