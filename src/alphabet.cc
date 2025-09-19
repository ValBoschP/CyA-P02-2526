/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 18/09/2025
 * Archivo alphabet.cc: Implementación de los métodos de la clase Alfabeto.
 * Este archivo contiene la implementación de los métodos de la clase Alfabeto.
 * Referencias:
 * Historial de revisiones
 * 18/09/2024 - Creación (primera versión) del código
 */

#include "alphabet.h"

#include <sstream>

/**
 * @brief Constructs an Alphabet object from a string of symbols.
 *
 * Iterates through each character in the provided string and inserts it into the
 * alphabet, excluding the '&' character. The resulting alphabet will contain unique
 * symbols from the input string, except for '&'.
 *
 * @param symbols A string containing the symbols to be included in the alphabet.
 */
Alphabet::Alphabet(const std::string& symbols) {
  for (char symbol : symbols) {
    if (symbol != '&') {
      symbols_.insert(symbol);
    }
  }
}

/**
 * @brief Returns a string representation of the alphabet.
 *
 * Concatenates all symbols in the alphabet into a single std::string.
 * The order of symbols in the resulting string corresponds to the order
 * returned by GetSymbols().
 *
 * @return A std::string containing all symbols of the alphabet.
 */
std::string Alphabet::GetStringAlphabet() const {
  std::stringstream alphabet;
  for (const auto& symbol : GetSymbols()) {
    alphabet << symbol;
  }
  return alphabet.str();
}

/**
 * @brief Overloads the output stream operator to print the contents of an Alphabet object.
 *
 * This function prints the symbols of the given Alphabet in a comma-separated list
 * enclosed in curly braces. If the alphabet is empty, it outputs a warning message.
 *
 * @param os The output stream to write to.
 * @param alphabet The Alphabet object whose symbols are to be printed.
 * @return std::ostream& Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  if (alphabet.IsEmpty()) {
    os << "The alphabet cannot be empty";
    return os;
  }
  os << "{";
  for (const auto& symbol : alphabet.GetSymbols()) {
    if (symbol == *alphabet.GetSymbols().rbegin()) {
      os << symbol;
      break;
    }
    os << symbol << ", ";
  }
  os << "}";
  return os;
}