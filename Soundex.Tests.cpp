#include <stdio.h>
#include <string.h>
#include "Soundex.h"

int test_empty_string();
int test_single_letter();
int test_typical_name();
int test_case_insensitivity();
int test_short_name();
int test_special_characters();
int test_spaces_in_name();
int test_special_characters_and_digits();
int test_numbers_in_name();
int test_repeated_consonants();
int test_hyphens_in_name();

int test_empty_string() {
    char result[5];
    generateSoundex("", result);
    return strcmp(result, "0000") == 0 ? 0 : 1;
}

int test_single_letter() {
    char result[5];
    generateSoundex("A", result);
    return strcmp(result, "A000") == 0 ? 0 : 1;
}

int test_typical_name() {
    char result[5];
    generateSoundex("Raghav", result);
    return strcmp(result, "R210") == 0 ? 0 : 1;
}

int test_case_insensitivity() {
    char result1[5], result2[5];
    generateSoundex("Avinash", result1);
    generateSoundex("avinash", result2);
    return strcmp(result1, result2) == 0 ? 0 : 1;
}

int test_short_name() {
    char result[5];
    generateSoundex("Avi", result);
    return strcmp(result, "A100") == 0 ? 0 : 1;
}

int test_special_characters() {
    char result[5];
    generateSoundex("Ravi@#$", result);
    return strcmp(result, "R100") == 0 ? 0 : 1;
}

int test_spaces_in_name() {
    char result[5];
    generateSoundex("Arvind Rao", result);
    int status = strcmp(result, "A615") == 0 ? 0 : 1;
    return status;
}

int test_special_characters_and_digits() {
    char result[5];
    generateSoundex("Manoj@123", result);
    return strcmp(result, "M520") == 0 ? 0 : 1;
}

int test_numbers_in_name() {
    char result[5];
    generateSoundex("avina2", result);
    return strcmp(result, "A150") == 0 ? 0 : 1;
}

int test_repeated_consonants() {
    char result[5];
    generateSoundex("Shashank", result);
    return strcmp(result, "S252") == 0 ? 0 : 1;
}

int test_hyphens_in_name() {
    char result[5];
    generateSoundex("Hari-Prasad", result);
    return strcmp(result, "H616") == 0 ? 0 : 1;
}

int main() {
    int totalFailedTests = 0;

    totalFailedTests += test_empty_string();
    totalFailedTests += test_single_letter();
    totalFailedTests += test_typical_name();
    totalFailedTests += test_case_insensitivity();
    totalFailedTests += test_short_name();
    totalFailedTests += test_special_characters();
    totalFailedTests += test_spaces_in_name();
    totalFailedTests += test_special_characters_and_digits();
    totalFailedTests += test_numbers_in_name();
    totalFailedTests += test_repeated_consonants();
    totalFailedTests += test_hyphens_in_name();

    if (totalFailedTests == 0) {
        return 0; // All tests passed
    } else {
        return 1; // Some tests failed
    }
}
