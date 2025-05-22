/*
 * File: transmission_utils.h
 * Description: Declaración de funciones de utilidad para análisis de transmisiones.
 * Author: Bernardo Caballero
 * Date: Mayo 2025
 */

 #ifndef TRANSMISSION_UTILS_H
 #define TRANSMISSION_UTILS_H
 
 #include <string>
 #include <utility>
 #include <vector>
 
 using namespace std;
 
 /**
  * Reads the entire content of a file.
  * @param filename Path to the file.
  * @return File content as a string.
  */
 string readFileContent(const string& filename);
 
 /**
  * Checks if a pattern exists in a text.
  * @param text The text to search in.
  * @param pattern The pattern to look for.
  * @return Pair (true, position+1) if found, (false, 0) otherwise.
  */
 pair<bool, size_t> contains_Pattern(const string& text, const string& pattern);
 
 /**
  * Finds the longest palindromic substring in the text.
  * @param text The input text.
  * @return Pair of 1-based start and end positions of the longest palindrome.
  */
 pair<int, int> longest_Palindrome(const string& text);
 
 /**
  * Finds the longest common substring between two texts.
  * @param text1 First text.
  * @param text2 Second text.
  * @return Pair of 1-based start and end positions of the substring in text1.
  */
 pair<int, int> longest_Common_Substring(const string& text1, const string& text2);
 
 #endif
 