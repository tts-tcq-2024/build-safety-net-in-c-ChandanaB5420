#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Helper function to convert a character to its Soundex code
char getSoundexCode(char c) {
    // Convert character to uppercase
    c = toupper(c);

    // Create a lookup table where each index corresponds to a letter of the alphabet
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '3', // A, B, C, D, E, F, G, H
        '0', '2', '0', '3', '0', '1', '0', '2', // I, J, K, L, M, N, O, P
        '1', '2', '0', '3', '0', '1', '0', '2', // Q, R, S, T, U, V, W, X
        '2', '0', '0'                           // Y, Z, [out of range]
    };

    // Return the Soundex code from the lookup table
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    }

    return '0'; // For non-alphabetic characters
}
// Simplified pure function to generate Soundex code
char getSoundexCode(char c);

void generateSoundex(const char *name, char *soundex) {
    // Ensure that name is not NULL and soundex is a valid pointer
    if (name == NULL || soundex == NULL) {
        return;
    }

    // Convert the first character and assign Soundex code
    soundex[0] = toupper(name[0]);
    soundex[1] = getSoundexCode(name[1]);
    soundex[2] = getSoundexCode(name[2]);
    soundex[3] = getSoundexCode(name[3]);

    // Fill remaining positions with '0' and terminate
    for (int i = 1; i < 4; ++i) {
        if (soundex[i] == '\0') {
            soundex[i] = '0';
        }
    }
    soundex[4] = '\0'; // Null-terminate
}
#endif // SOUNDEX_H
