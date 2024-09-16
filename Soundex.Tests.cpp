#include <stdio.h>
#include <string.h>
#include "Soundex.h"

int test_empty_string_returns_code_padded_with_four_zeros();
int test_single_letter_returns_letter_with_zeros();
int test_typical_name_returns_expected_code();
int test_case_insensitivity_returns_same_code();
int test_short_name_returns_letter_with_truncated_code();
int test_special_characters_ignored_in_code();
int test_spaces_in_name_ignored_in_code();
int test_special_characters_and_digits_ignored_in_code();
int test_numbers_in_name_processed_as_letters();
int test_repeated_consonants_compressed_in_code();
int test_hyphens_in_name_ignored_in_code();

int test_empty_string_returns_code_padded_with_four_zeros() {
    char result[5];
    generateSoundex("", result);
    return strcmp(result, "0000") == 0 ? 0 : 1;
}

int test_single_letter_returns_letter_with_zeros() {
    char result[5];
    generateSoundex("A", result);
    return strcmp(result, "A000") == 0 ? 0 : 1;
}

int test_typical_name_returns_expected_code() {
    char result[5];
    generateSoundex("Raghav", result);
    return strcmp(result, "R210") == 0 ? 0 : 1;
}

int test_case_insensitivity_returns_same_code() {
    char result1[5], result2[5];
    generateSoundex("Avinash", result1);
    generateSoundex("avinash", result2);
    return strcmp(result1, result2) == 0 ? 0 : 1;
}

int test_short_name_returns_letter_with_truncated_code() {
    char result[5];
    generateSoundex("Avi", result);
    return strcmp(result, "A100") == 0 ? 0 : 1;
}

int test_special_characters_ignored_in_code() {
    char result[5];
    generateSoundex("Ravi@#$", result);
    return strcmp(result, "R100") == 0 ? 0 : 1;
}

int test_spaces_in_name_ignored_in_code() {
    char result[5];
    generateSoundex("Arvind Rao", result);
    int status = strcmp(result, "A615") == 0 ? 0 : 1;
    return status;
}

int test_special_characters_and_digits_ignored_in_code() {
    char result[5];
    generateSoundex("Manoj@123", result);
    return strcmp(result, "M520") == 0 ? 0 : 1;
}

int test_numbers_in_name_processed_as_letters() {
    char result[5];
    generateSoundex("avina2", result);
    return strcmp(result, "A150") == 0 ? 0 : 1;
}

int test_repeated_consonants_compressed_in_code() {
    char result[5];
    generateSoundex("Shashank", result);
    return strcmp(result, "S252") == 0 ? 0 : 1;
}

int test_hyphens_in_name_ignored_in_code() {
    char result[5];
    generateSoundex("Hari-Prasad", result);
    return strcmp(result, "H616") == 0 ? 0 : 1;
}

int main() {
    int totalFailedTests = 0;

    totalFailedTests += test_empty_string_returns_code_padded_with_four_zeros();
    totalFailedTests += test_single_letter_returns_letter_with_zeros();
    totalFailedTests += test_typical_name_returns_expected_code();
    totalFailedTests += test_case_insensitivity_returns_same_code();
    totalFailedTests += test_short_name_returns_letter_with_truncated_code();
    totalFailedTests += test_special_characters_ignored_in_code();
    totalFailedTests += test_spaces_in_name_ignored_in_code();
    totalFailedTests += test_special_characters_and_digits_ignored_in_code();
    totalFailedTests += test_numbers_in_name_processed_as_letters();
    totalFailedTests += test_repeated_consonants_compressed_in_code();
    totalFailedTests += test_hyphens_in_name_ignored_in_code();

    if (totalFailedTests == 0) {
        printf("All tests passed!\n");
    } else {
        printf("%d tests failed.\n", totalFailedTests);
    }

    return 0;
}
