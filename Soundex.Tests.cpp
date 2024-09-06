#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Soundex.h"

// Function to test Soundex encoding with descriptive messages
void testSoundex(const char *name, const char *expected, const char *testDescription) {
    char soundex[5];
    generateSoundex(name, soundex);
    if (strcmp(soundex, expected) != 0) {
        printf("Test failed: %s\n", testDescription);
        printf("Expected '%s', got '%s'\n", expected, soundex);
    } else {
        printf("Test passed: %s\n", testDescription);
    }
}

int main() {
    // Test: Empty input should return '0000'
    testSoundex("", "0000", "Empty input should return '0000'");

    // Test: Single letter 'A' should return 'A000'
    testSoundex("A", "A000", "Single letter 'A' should return 'A000'");

    // Test: Name 'Raghav' becomes 'R210'
    testSoundex("Raghav", "R210", "Name 'Raghav' should become 'R210'");

    // Test: Case-insensitive comparison for 'Avinash' and 'avinash'
    // Ensure generateSoundex is case-insensitive
    testSoundex("Avinash", generateSoundex("avinash"), "Case-insensitive comparison for 'Avinash' and 'avinash'");

    // Test: Short name 'Avi' becomes 'A100'
    testSoundex("Avi", "A100", "Short name 'Avi' should become 'A100'");

    // Test: Special characters are ignored in name 'Ravi@#$'
    testSoundex("Ravi@#$", "R100", "Special characters are ignored in name 'Ravi@#$'");

    // Test: Spaces are ignored in 'Arvind Rao' and 'Sandeep Prasad'
    testSoundex("Arvind Rao", "A615", "Spaces are ignored in 'Arvind Rao'");
    testSoundex("Sandeep  Prasad", "S531", "Spaces are ignored in 'Sandeep  Prasad'");

    // Test: Special characters and digits are ignored in 'Manoj@123'
    testSoundex("Manoj@123", "M520", "Special characters and digits are ignored in 'Manoj@123'");

    // Test: Numbers in name are ignored in 'avina2'
    testSoundex("avina2", "A150", "Numbers in name are ignored in 'avina2'");

    // Test: Name with repeated consonants 'Shashank' becomes 'S252'
    testSoundex("Shashank", "S252", "Name with repeated consonants 'Shashank' should become 'S252'");

    // Test: Name with hyphens ignored in 'Hari-Prasad'
    testSoundex("Hari-Prasad", "H616", "Name with hyphens ignored in 'Hari-Prasad'");

    return 0;
}
