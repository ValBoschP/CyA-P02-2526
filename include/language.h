/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 18/09/2025
 * Archivo language.h: Declaración de la clase Lenguaje.
 * Este archivo contiene la declaración de la clase Lenguaje y sus métodos para
 * realizar operaciones como unión, intersección, diferencia y concatenación
 * de lenguajes, así como la sobrecarga de operadores y la impresión de lenguajes.
 * Referencias:
 * Historial de revisiones:
 * 18/09/2025 - Creación (primera versión) del código
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "string.h"

#include <set>

/**
 * @class Language
 * @brief Represents a formal language as a set of strings (String).
 *
 * The Language class provides methods to manipulate formal languages,
 * allowing operations such as union, intersection, difference, and concatenation
 * between languages. Each language is internally represented as a set of String objects.
 */
class Language {
 public:
  // -- CONSTRUCTORS --
  Language() = default;
  Language(const std::set<String>& strings) : strings_(strings) {}
  Language(const std::set<std::string>& strings);
  Language(const String& str) { strings_.insert(str); }
  Language(const std::string& str) { strings_.insert(String(str)); }

  // -- GETTERS --
  inline std::set<String> GetStrings() const { return strings_; }
  inline Language GetLanguage() const { return *this; }

  // -- METHODS -- 
  void AddString(const String& str);
  void AddString(const std::string& str);

  bool IsEmpty() const { return strings_.empty(); }
  int Cardinality() const { return strings_.size(); }

  Language Union(const Language& language);
  Language Intersection(const Language& language);
  Language Difference(const Language& language);
  Language Concatenation(const Language& language);

  // -- OPERATORS --
  friend std::ostream& operator<<(std::ostream& os, const Language& language);

  Language operator+(const Language& language) { return Union(language); } 
  Language operator*(const Language& language) { return Concatenation(language); }
  Language operator-(const Language& language) { return Difference(language); }
  Language operator|(const Language& language) { return Intersection(language); }

  bool operator==(const Language& language) const { return strings_ == language.GetStrings(); }
  bool operator!=(const Language& language) const { return strings_ != language.GetStrings(); }
  bool operator<(const Language& language) const { return strings_ < language.GetStrings(); }
  bool operator>(const Language& language) const { return strings_ > language.GetStrings(); }

 private:
  std::set<String> strings_;
};

#endif  // LANGUAGE_H