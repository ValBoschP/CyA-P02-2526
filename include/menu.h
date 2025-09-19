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
 * sobre las cadenas de entrada. Estas funciones usan la clase Cadena y otras utilidades
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

std::string ProcessAlphabet(const Cadena& cadena);   // opcode: 1
std::string ProcessLength(const Cadena& cadena);     // opcode: 2
std::string ProcessInverse(const Cadena& cadena);    // opcode: 3
std::string ProcessPrefixes(const Cadena& cadena);   // opcode: 4
std::string ProcessSuffixes(const Cadena& cadena);   // opcode: 5

std::string ProcessPalindrome(const Cadena& cadena);
std::string ProcessRepetitions(const Cadena& cadena, int n_times);
std::string BelongsToAlphabet(const Cadena& cadena);

std::vector<std::string> ProcessStrings(const std::vector<Cadena>& cadenas, int opcode);

#endif  // MENU_H