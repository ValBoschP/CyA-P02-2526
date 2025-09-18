/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 18/09/2025
 * Archivo alphabet.h: Declaración de la clase ALphabet.
 * Este archivo contiene la declaración de la clase ALphabet y sus métodos para 
 * realizar operaciones como obtener el alphabet, agregar y eliminar símbolos,
 * comprobar si un símbolo pertenece al alphabet, y obtener la cardinalidad del alphabet.
 * Referencias:
 * Historial de revisiones
 * 18/09/2025 - Creación (primera versión) del código
 */
#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

/**
 * @class Alphabet
 * @brief Class representing an alphabet composed of a set of symbols.
 */
class Alphabet {
 public:
  // -- CONSTRUCTORS --
  Alphabet() = default;
  Alphabet(const std::set<char>& symbols) : symbols_(symbols) {}
  Alphabet(const std::string& symbols);

  // -- GETTERS --
  inline std::set<char> GetSymbols() const { return symbols_; }
  inline Alphabet GetAlphabet() const { return *this; }
  std::string GetStringAlphabet() const;

  // -- METHODS --
  inline void AddSymbol(const char& symbol) { symbols_.insert(symbol); }
  inline void RemoveSymbol(const char& symbol) { symbols_.erase(symbol); }

  bool Contains(const char& symbol) const { return symbols_.find(symbol) != symbols_.end(); }
  bool IsEmpty() const { return symbols_.empty(); } // An alphabet cannot be empty
  int Cardinality() const { return static_cast<int>(symbols_.size()); }

  // -- OPERATORS --
  bool operator==(const Alphabet& alphabet) const { return symbols_ == alphabet.GetSymbols(); }
  bool operator!=(const Alphabet& alphabet) const { return symbols_ != alphabet.GetSymbols(); }
  bool operator<(const Alphabet& alphabet) const { return symbols_ < alphabet.GetSymbols(); }
  bool operator>(const Alphabet& alphabet) const { return symbols_ > alphabet.GetSymbols(); }
  bool operator<=(const Alphabet& alphabet) const { return symbols_ <= alphabet.GetSymbols(); }
  bool operator>=(const Alphabet& alphabet) const { return symbols_ >= alphabet.GetSymbols(); }

  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

 private:
  std::set<char> symbols_;
};

#endif // ALPHABET_H
