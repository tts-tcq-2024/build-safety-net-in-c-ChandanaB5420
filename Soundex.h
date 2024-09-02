#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Helper function to convert a character to its Soundex code
char getSoundexCode(char c) {
    c = toupper(c);
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') return '1';
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') return '2';
    if (c == 'D' || c == 'T') return '3';
    if (c == 'L') return '4';
    if (c == 'M' || c == 'N') return '5';
    if (c == 'R') return '6';
    return '0'; // For A, E, I, O, U, H, W, Y
}

// Simplified pure function to generate Soundex code
void generateSoundex(const char *name, char *soundex) {
    // Ensure that name is not NULL and soundex is a valid pointer
    if (name == NULL || soundex == NULL) {
        return;
    }

    // Handle empty name case
    if (name[0] == '\0') {
        strcpy(soundex, "0000");
        return;
    }

    // Basic case for a pure function with no loops or conditions
    soundex[0] = toupper(name[0]);
    soundex[1] = getSoundexCode(name[1]); // Fixed index access
    soundex[2] = getSoundexCode(name[2]); // Fixed index access
    soundex[3] = getSoundexCode(name[3]); // Fixed index access

    // Fill remaining with '0'
    if (name[1] == '\0') soundex[1] = '0';
    if (name[2] == '\0') soundex[2] = '0';
    if (name[3] == '\0') soundex[3] = '0';

    soundex[4] = '\0'; // Null-terminate
}

#endif // SOUNDEX_H
