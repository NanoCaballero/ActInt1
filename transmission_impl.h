
// File: transmission_utils.h

/*
 * Archivo: transmission_impl.h
 * Descripción: Funciones para análisis de transmisiones
 * Autor: Bernardo Caballero
 * Fecha: Mayo 2025
 */

#ifndef TRANSMISSION_IMPL_H
#define TRANSMISSION_IMPL_H

#include "transmission_utils.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Lee el contenido completo de un archivo de texto.
 * 
 * @param filename Ruta del archivo a leer.
 * @return std::string Contenido del archivo.
 * @throws Sale del programa si el archivo no se puede abrir.
 */
string read_file_content(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

/**
 * Verifica si un patrón existe dentro del texto.
 * 
 * @param text El texto donde se buscará.
 * @param pattern El patrón a buscar.
 * @return Un par: el primero indica si se encontró el patrón, 
 *         el segundo es la posición (1-based) o 0 si no se encontró.
 */
pair<bool, size_t> contains_pattern(const string &text, const string &pattern) {
    size_t pos = text.find(pattern);
    return (pos != string::npos) ? make_pair(true, pos + 1) : make_pair(false, static_cast<size_t>(0));
}

/**
 * Encuentra el substring palindrómico más largo dentro de un texto.
 * 
 * @param text El texto a analizar.
 * @return Un par de enteros indicando el inicio y fin del palíndromo (1-based).
 */
pair<int, int> longest_palindrome(const string &text) {
    int n = text.size();
    if (n == 0) return {1, 1};

    int maxLen = 1, start = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; (i - j >= 0) && (i + j < n) && (text[i - j] == text[i + j]); ++j) {
            if (2 * j + 1 > maxLen) {
                maxLen = 2 * j + 1;
                start = i - j;
            }
        }
        for (int j = 0; (i - j >= 0) && (i + j + 1 < n) && (text[i - j] == text[i + j + 1]); ++j) {
            if (2 * j + 2 > maxLen) {
                maxLen = 2 * j + 2;
                start = i - j;
            }
        }
    }
    return {start + 1, start + maxLen};
}

/**
 * Encuentra el substring común más largo entre dos textos.
 * 
 * @param text1 El primer texto.
 * @param text2 El segundo texto.
 * @return Un par con el índice de inicio y final (1-based) del substring común más largo.
 */
pair<int, int> longest_common_substring(const string &text1, const string &text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0, endIdx = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIdx = i;
                }
            }
        }
    }
    return {endIdx - maxLen + 1, endIdx};
}

#endif
