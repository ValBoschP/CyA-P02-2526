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

Alphabet::Alphabet(const std::string& symbols) {
  for (char symbol : symbols) {
    if (symbol != '&') {
      symbols_.insert(symbol);
    }
  }
}

std::string Alphabet::GetStringAlphabet() const {
  std::stringstream alphabet;
  for (const auto& symbol : GetSymbols()) {
    alphabet << symbol;
  }
  return alphabet.str();
}

std::ostream&operator<<(std::ostream os, const Alphabet& alphabet) {
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