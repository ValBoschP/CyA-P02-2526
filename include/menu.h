/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 19/09/2025
 * Archivo menu.h: Declaración de funciones de procesamiento.
 * Este archivo contiene la declaración de las funciones de procesamiento que
 * ejecutan las operaciones solicitadas (alfabeto, longitud, inversa, prefijos, sufijos)
 * sobre las cadenas de entrada. Estas funciones usan la clase String y otras utilidades
 * para producir los resultados adecuados.
 * Referencias:
 * Historial de revisiones:
 * 19/09/2025 - Creación (primera versión) del código
 */

#ifndef MENU_H
#define MENU_H

#include "string.h"
#include "language.h"
#include "file.h"

#include <string>
#include <vector>

void ShowHelp();
bool ValidateParameters(int argc, char* argv[]);

void Program(int argc, char* argv[]);

std::string ProcessAlphabet(const String& string);   // opcode: 1
std::string ProcessLength(const String& string);     // opcode: 2
std::string ProcessInverse(const String& string);    // opcode: 3
std::string ProcessPrefixes(const String& string);   // opcode: 4
std::string ProcessSuffixes(const String& string);   // opcode: 5

std::string ProcessPalindrome(const String& string);
std::string ProcessRepetitions(const String& string, int n_times);
std::string BelongsToAlphabet(const String& string);

std::vector<std::string> ProcessStrings(const std::vector<String>& strings, int opcode);

#endif  // MENU_H