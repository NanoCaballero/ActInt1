
// Archivo: transmission_test.cpp

/*
 * Archivo: transmission_test.cpp
 * Descripción: Funciones para análisis de transmisiones
 * Autor: Bernardo Caballero
 * Fecha: Mayo 2025
 */

#include <gtest/gtest.h>
#include "../transmission_utils.h"
#include "../transmission_impl.h"

TEST(PatternTest, Found) {
    std::string t = "ABCDEF";
    std::string p = "CDE";
    auto res = contains_Pattern(t, p);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 3);
}

TEST(PatternTest, NotFound) {
    std::string t = "ABCDEF";
    std::string p = "XYZ";
    auto res = contains_Pattern(t, p);
    EXPECT_FALSE(res.first);
    EXPECT_EQ(res.second, 0);
}


TEST(PalindromeTest, Basic) {
    std::string t = "ABBA";
    auto res = longest_Palindrome(t);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 4);
}

TEST(PalindromeTest, Empty) {
    std::string t = "";
    auto res = longest_Palindrome(t);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 1);
}

TEST(PalindromeTest, OneChar) {
    std::string t = "A";
    auto res = longest_Palindrome(t);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 1);
}


TEST(CommonSubstrTest, Match) {
    std::string a = "ABXYZCD";
    std::string b = "XYZABCD";
    auto res = longest_Common_Substring(a, b);
    EXPECT_EQ(res.first, 3);
    EXPECT_EQ(res.second, 5);
}

TEST(CommonSubstrTest, NoMatch) {
    std::string a = "ABC";
    std::string b = "XYZ";
    auto res = longest_Common_Substring(a, b);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 0);
}

TEST(PatternTest, PatternAtBeginning) {
    std::string t = "HELLO";
    std::string p = "HEL";
    auto res = contains_Pattern(t, p);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 1);
}

TEST(PatternTest, PatternAtEnd) {
    std::string t = "HELLO";
    std::string p = "LO";
    auto res = contains_Pattern(t, p);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 4);
}

TEST(PalindromeTest, WholeTextPalindrome) {
    std::string t = "MADAM";
    auto res = longest_Palindrome(t);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 5);
}

TEST(CommonSubstrTest, FullMatch) {
    std::string a = "SAME";
    std::string b = "SAME";
    auto res = longest_Common_Substring(a, b);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 4);
}

TEST(CommonSubstrTest, OneCharMatch) {
    std::string a = "A";
    std::string b = "A";
    auto res = longest_Common_Substring(a, b);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 1);
}
