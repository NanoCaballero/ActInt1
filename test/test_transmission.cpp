#include <cassert>
#include <string>
#include "/Users/bernardocaballero/Downloads/A01722757_ActInt1/main.cpp"

void testContainsPattern() {
    std::string text = "ABCDEF123456";
    std::string pattern = "DEF1";
    auto result = containsPattern(text, pattern);
    assert(result.first == true);
    assert(result.second == 4);
}

void testLongestPalindrome() {
    std::string text = "ABCDDCBA";
    auto result = longestPalindrome(text);
    assert(result.first == 1);
    assert(result.second == 8);
}

void testLongestCommonSubstring() {
    std::string text1 = "ABCDEFG";
    std::string text2 = "XYZABCQW";
    auto result = longestCommonSubstring(text1, text2);
    assert(result.first == 1);
    assert(result.second == 3); // ABC
}

int main() {
    testContainsPattern();
    testLongestPalindrome();
    testLongestCommonSubstring();
    return 0;
}
