#ifndef SOUNDEX_H
#define SOUNDEX_H

char getSoundexCode(char c);
char* generateSoundex(const char *name);

#endif // SOUNDEX_H

cpp
Copy code
#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

// Simplifies the addition of a Soundex code character
char* addCodeToSoundex(const char *name, char previousCode, int sIndex) {
    char code = getSoundexCode(*name);

    // Return early if we reach the end of the string or Soundex length is 4
    if (*name == '\0' || sIndex >= 4) {
        char *result = (char*)malloc(5 * sizeof(char));
        if (!result) return NULL; // Handle allocation failure
        memset(result, '0', 4); // Fill with '0'
        result[4] = '\0';
        return result;
    }

    // Decide if the code should be added
    if (code != '0' && code != previousCode) {
        char *result = (char*)malloc(5 * sizeof(char));
        if (!result) return NULL; // Handle allocation failure
        result[0] = code;
        result[1] = '\0';
        char *rest = addCodeToSoundex(name + 1, code, sIndex + 1);
        if (rest) {
            strcat(result, rest);
            free(rest);
        }
        return result;
    } else {
        return addCodeToSoundex(name + 1, previousCode, sIndex);
    }
}

// Generates the Soundex code from a given name
char* generateSoundex(const char *name) {
    if (*name == '\0') {
        char *result = (char*)malloc(5 * sizeof(char));
        if (!result) return NULL; // Handle allocation failure
        result[0] = '\0'; // Handle empty name
        return result;
    }

    char *result = (char*)malloc(5 * sizeof(char));
    if (!result) return NULL; // Handle allocation failure
    result[0] = toupper(*name);
    result[1] = '\0'; // Start with the first character
    char *rest = addCodeToSoundex(name + 1, getSoundexCode(*name), 1);
    if (rest) {
        strcat(result, rest);
        free(rest);
    }
    
    return result;
}
