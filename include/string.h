/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 18/09/2025
 * Archivo string.h: Declaración de la clase String.
 * Este archivo contiene la declaración de la clase String y sus métodos para
 * realizar operaciones como obtener el alfabeto, longitud, inversa, prefijos y sufijos.
 * Referencias:
 * Historial de revisiones:
 * 18/09/2025 - Creación (primera versión) del código
 */

#ifndef STRING_H
#define STRING_H

#include "alphabet.h"

#include <string>
#include <vector>
#include <algorithm>
#include <set>

class Language; // Forward declaration

/**
 * @class String
 * @brief Represents a string with an associated alphabet and provides various operations.
 */
class String {
 public:
  // -- CONSTRUCTORS --
  String() = default;
  String(const std::string& string, const Alphabet& alphabet) : string_(string), alphabet_(alphabet) {}
  String(const std::string& string, const std::string& alphabet);
  String(const std::string& string) : string_(string) {}
  String(const String& string, const Alphabet& alphabet) : string_(string.GetStringString()), alphabet_(alphabet) {}
  String(const String& string) : string_(string.GetStringString()), alphabet_(string.GetAlphabet()) {}

  // -- GETTERS --
  inline std::string GetStringString() const { return string_; }
  inline String GetString() const { return *this; }
  inline Alphabet GetAlphabet() const { return alphabet_; }
  inline std::set<char> GetSetAlphabet() const { return alphabet_.GetSymbols(); }
  std::string GetStringAlphabet() const { return alphabet_.GetStringAlphabet(); }

  // -- METHODS --
  int Length() const;

  String Inverse() const;
  String Concatenation(const String& string) const;
  String Power(int n) const;

  std::string InverseString() const;
  std::set<std::string> Prefixes() const;
  std::set<std::string> Suffixes() const;
  std::set<std::string> Substrings() const;
  std::set<std::string> SetConcatenation(const String& string) const;

  Language LangPrefixes() const;
  Language LangSuffixes() const;
  Language LangSubstrings() const;

  bool BelongsToAlphabet() const;

  // -- OPERATORS --
  bool operator<(const String& string) const;
  bool operator<=(const String& string) const;
  bool operator>(const String& string) const;
  bool operator>=(const String& string) const;
  bool operator==(const String& string) const;
  bool operator!=(const String& string) const;

  friend std::ostream& operator<<(std::ostream& os, const String& string);
 private:
  std::string string_;
  Alphabet alphabet_;
};

#endif // STRING_H