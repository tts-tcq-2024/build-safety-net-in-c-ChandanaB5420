#include <stdio.h>
#include <ctype.h>

// Function to get the Soundex code for a single character
char getSoundexCode(char c) {
    switch (toupper(c)) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}

// Function to process a single character and update the Soundex code
void processCharacter(const char *name, char *soundex, int *index, char previousCode) {
    if (name[0] == '\0' || *index >= 4) {
        return;
    }

    char currentCode = getSoundexCode(name[0]);
    if (currentCode != '0' && currentCode != previousCode) {
        soundex[*index] = currentCode;
        (*index)++;
    }

    processCharacter(name + 1, soundex, index, currentCode);
}

// Wrapper function to get the Soundex code for a name
void getSoundexCodeForName(const char *name, char *soundex) {
    int index = 1;
    soundex[0] = toupper(name[0]);
    processCharacter(name + 1, soundex, &index, getSoundexCode(name[0]));

    // Pad with zeros if necessary
    while (index < 4) {
        soundex[index++] = '0';
    }
    soundex[index] = '\0';
}

int main() {
    char name[100];
    char soundex[5];

    printf("Enter a name: ");
    scanf("%s", name);

    getSoundexCodeForName(name, soundex);
    printf("Soundex code for %s is %s\n", name, soundex);

    return 0;
}
