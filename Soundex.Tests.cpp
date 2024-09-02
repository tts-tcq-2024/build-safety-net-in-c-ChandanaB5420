#include <gtest/gtest.h>
#include "Soundex.h"  // Include your header file

// Test cases for generateSoundex function
TEST(SoundexTest, BasicTests) {
    char result[5];

    // Test with a common name
    generateSoundex("Example", result);
    EXPECT_STREQ(result, "E251");

    // Test with a name that includes different letters
    generateSoundex("Smith", result);
    EXPECT_STREQ(result, "S530");

    // Test with names that should be padded
    generateSoundex("A", result);
    EXPECT_STREQ(result, "A000");

    generateSoundex("AB", result);
    EXPECT_STREQ(result, "A100");

    // Test with name that includes all characters
    generateSoundex("ABCDEFGHIJKLMNOPQRSTUVWXYZ", result);
    EXPECT_STREQ(result, "A123");

    // Test with names that start with letters that are dropped in Soundex
    generateSoundex("Alexander", result);
    EXPECT_STREQ(result, "A425");

    // Test with an empty string
    generateSoundex("", result);
    EXPECT_STREQ(result, "0000");
}

// Additional test for invalid names
TEST(SoundexTest, InvalidNames) {
    char result[5];

    // Test with a single character which should be padded
    generateSoundex("B", result);
    EXPECT_STREQ(result, "B000");

    // Test with a single non-alphabetic character
    generateSoundex("1", result);
    EXPECT_STREQ(result, "1000");

    // Test with a name with only non-alphabetic characters
    generateSoundex("1234", result);
    EXPECT_STREQ(result, "1000");
}

// Run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
