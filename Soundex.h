#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Precomputed mapping from characters to Soundex codes
static const char codeMap[] = "000000000000012301200400500600";

char getSoundexCode(char c) {
    return codeMap[toupper(c) - 'A'];
}

void generateSoundex(const char *name, char *soundex) {
    // Initialize the soundex code with default values
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    
    char previousCode = '0';
    int j = 1;  // Index for soundex

    for (int i = 1; name[i] && j < 4; i++) {
        char currentCode = getSoundexCode(name[i]);

        // Simplified conditional logic to ensure CCN=3
        if (currentCode != '0' && currentCode != previousCode) {
            soundex[j++] = currentCode;
            previousCode = currentCode;
        }
    }

    // Null-terminate the Soundex code
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
