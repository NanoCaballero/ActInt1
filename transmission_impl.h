
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
 * Expande alrededor del centro y retorna la longitud y el inicio del palíndromo.
 * 
 * @param text El texto a analizar.
 * @param left Índice izquierdo inicial.
 * @param right Índice derecho inicial.
 * @return Un par: longitud y posición inicial.
 */
pair<int, int> expand_palindrome(const string &text, int left, int right) {
    int n = text.size();
    while (left >= 0 && right < n && text[left] == text[right]) {
        --left;
        ++right;
    }
    return {right - left - 1, left + 1};
}

/**
 * Encuentra el substring palindrómico más largo dentro de un texto.
 * 
 * @param text El texto a analizar.
 * @return Un par de enteros indicando el inicio y fin del palíndromo (1-based).
 */
pair<int, int> longest_palindrome(const string &text) {
    int n = text.size();
    if (n == 0) {
        return {1, 1};
    }    

    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < n; ++i) {
        auto [len1, start1] = expand_palindrome(text, i, i);     // impar
        auto [len2, start2] = expand_palindrome(text, i, i + 1); // par

        if (len1 > maxLen) {
            maxLen = len1;
            start = start1;
        }
        if (len2 > maxLen) {
            maxLen = len2;
            start = start2;
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
