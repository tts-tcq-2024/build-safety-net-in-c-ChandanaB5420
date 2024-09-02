#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "soundex.h"

// Pure test function to check Soundex results
void testSoundex(const char *name, const char *expected) {
    char *soundex = generateSoundex(name);
    assert(soundex != NULL); // Ensure memory allocation succeeded
    assert(strcmp(soundex, expected) == 0);
    printf("generateSoundex(\"%s\") = \"%s\"; Passed\n", name, soundex);
    free(soundex); // Free the allocated memory
}

int main() {
    // Test cases
    testSoundex("Smith", "S530");
    testSoundex("Jackson", "J252");
    testSoundex("Honeyman", "H555");
    testSoundex("Robert", "R163");
    testSoundex("Miller", "M460");
    testSoundex("Lee", "L000");

    // Edge cases
    testSoundex("", "0000");       // Empty string should return "0000"
    testSoundex("A", "A000");      // Single character input
    testSoundex("AB", "A120");     // Two character input
    testSoundex("A123", "A123");   // Input longer than 4 characters
    testSoundex("Hello", "H440");  // Typical case with a common name

    printf("All tests passed.\n");

    return 0;
}
