#include <gtest/gtest.h>
#include "soundex.h"

TEST(SoundexTest, BasicCases) {
    char soundex[5];

    generateSoundex("Smith", soundex);
    EXPECT_STREQ(soundex, "S530");

    generateSoundex("Jackson", soundex);
    EXPECT_STREQ(soundex, "J252");

    generateSoundex("Honeyman", soundex);
    EXPECT_STREQ(soundex, "H555");

    generateSoundex("Robert", soundex);
    EXPECT_STREQ(soundex, "R163");

    generateSoundex("Miller", soundex);
    EXPECT_STREQ(soundex, "M460");

    generateSoundex("Lee", soundex);
    EXPECT_STREQ(soundex, "L000");
}

TEST(SoundexTest, EdgeCases) {
    char soundex[5];

    generateSoundex("", soundex);
    EXPECT_STREQ(soundex, "0000");

    generateSoundex("A", soundex);
    EXPECT_STREQ(soundex, "A000");

    generateSoundex("AB", soundex);
    EXPECT_STREQ(soundex, "A120");

    generateSoundex("A123", soundex);
    EXPECT_STREQ(soundex, "A123");

    generateSoundex("Hello", soundex);
    EXPECT_STREQ(soundex, "H440");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
