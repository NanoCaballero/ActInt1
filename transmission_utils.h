
/*
 * Archivo: transmission_utils.h
 * Descripción: Funciones para análisis de transmisiones
 * Autor: Bernardo Caballero
 * Fecha: Mayo 2025
 */

#ifndef TRANSMISSION_UTILS_H
#define TRANSMISSION_UTILS_H

#include <string>
#include <utility>
#include <vector>

using namespace std;

string readFileContent(const string &filename);
pair<bool, size_t> contains_Pattern(const string &text, const string &pattern);
pair<int, int> longest_Palindrome(const string &text);
pair<int, int> longestCommonSubstring(const string &text1, const string &text2);

#endif
