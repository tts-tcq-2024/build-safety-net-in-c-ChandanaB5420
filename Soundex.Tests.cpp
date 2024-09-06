#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Soundex.h"  
 
void test_empty_string() {
    char result[5];
    generateSoundex("", result);
    assert(strcmp(result, "0000") == 0);
    printf("test_empty_string passed!\n");

}
 
void test_single_character() {
    char result[5];
    generateSoundex("A", result);
    assert(strcmp(result, "A000") == 0);
    printf("test_single_character passed!\n");

}
 
void test_typical_name() {
    char result[5];
    generateSoundex("Raghav", result);
    assert(strcmp(result, "R020") == 0);
    printf("test_typical_name passed!\n");

}
 
void test_case_insensitivity() {
    char result1[5];
    char result2[5];
    generateSoundex("Yashwanth", result1);
    generateSoundex("yashwanth", result2);
    assert(strcmp(result1, result2) == 0);
    printf("test_case_insensitivity passed!\n");

}
 
void test_padding_to_four_digits() {

    char result[5];

    generateSoundex("G", result);

    assert(strcmp(result, "G000") == 0);

    printf("test_padding_to_four_digits passed!\n");

}
 
void test_trimming_to_four_digits() {

    char result[5];

    generateSoundex("Shivakumar", result);

    assert(strcmp(result, "S152") == 0);

    printf("test_trimming_to_four_digits passed!\n");

}
 
void test_non_alphabetic_characters() {
    char result[5];
    generateSoundex("Ravi@#$", result);
    assert(strcmp(result, "R130") == 0);
    printf("test_non_alphabetic_characters passed!\n");
}
 
void test_names_with_spaces() {
    char result[5];
    generateSoundex("Anil Kumar", result);
    assert(strcmp(result, "A524") == 0);
    printf("test_names_with_spaces passed!\n");
    generateSoundex("Anil  Kumar", result);  // Multiple spaces
    assert(strcmp(result, "A524") == 0);
    printf("test_names_with_multiple_spaces passed!\n");
}
 
void test_special_characters_in_name() {
    char result[5];

    generateSoundex("Manoj@123", result);

    assert(strcmp(result, "M520") == 0);

    printf("test_special_characters_in_name passed!\n");

}
 
int main() {

    test_empty_string();

    test_single_character();

    test_typical_name();

    test_case_insensitivity();

    test_padding_to_four_digits();

    test_trimming_to_four_digits();

    test_non_alphabetic_characters();

    test_names_with_spaces();

    test_special_characters_in_name();

    printf("All tests passed!\n");

    return 0;

}

 
