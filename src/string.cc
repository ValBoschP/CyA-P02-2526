/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 18/09/2025
 * Archivo string.cc: Implementación de los métodos de la clase String.
 * Este archivo contiene la implementación de los métodos de la clase Cadena.
 * Referencias:
 * Historial de revisiones:
 * 18/09/2025 - Creación (primera versión) del código
 */

#include "string.h"

#include <algorithm>

String::String(const std::string& string, const std::string& alphabet) : string_(string) {
  for (const auto& symbol : alphabet) {
    alphabet_.AddSymbol(symbol);
  }
}

std::string String::GetStringAlphabet() const {
  return alphabet_.GetStringAlphabet();
}

int String::Length() const {
  if (string_ == "&") return 0;
  return string_.length();
}

String String::Inverse() const {
  if (string_.empty() || string_ == "&") return String("&");
  std::string reversed_string(string_.rbegin(), string_.rend());
  return String(reversed_string);
}

std::string String::InverseString() const {
  if (string_.empty() || string_ == "&") return "&";
  return std::string(string_.rbegin(), string_.rend());
}

std::set<std::string> String::Prefixes() const {
  std::set<std::string> result;
  std::string prefix;
  if (string_ == "&") {
    prefixes.insert("");
    return result;
  }
  result.insert("&");
  for (const auto& symbol : string_) {
    prefix += symbol;
    result.insert(prefix);
  }
  return result;
}

std::set<std::string> String::Suffixes() const {
  std::set<std::string> result;
  std::string suffix;
  if (string_ == "&") {
    result.insert("");
    return result;
  }
  result.insert("&");
  for (auto symbol = string_.rbegin(); symbol != string_.rend(); ++symbol) {
    suffix = *symbol + suffix;
    result.insert(suffix);
  }
  return result;
}

std::set<std::string> String::Substrings() const {
  std::set<std::string> result;
  std::string current_string = string_;
  for (int i = 0; i < current_string.length(); ++i) {
    for (int j = i + 1; j <= current_string.length(); ++j) {
      result.insert(current_string.substr(i, j - i));
    }
  }
  return result;
}

String String::Power(const int n) const {
  if (n == 0) return String("&");
  std::string result;
  for (int i = 0; i < n; ++i) {
    result += string_;
  }
  return String(result, alphabet_);
}

bool String::BelongsToAlphabet() const {
  for (const auto& symbol : string_) {
    if (!alphabet_.Contains(symbol)) {
      return false;
    }
  }
  return true;
}

bool String::operator<(const String& string) const {
  return string_ < string.string_;
}

bool String::operator<=(const String& string) const {
  return string_ <= string.string_;
}

bool String::operator>(const String& string) const {
  return string_ > string.string_;
}

bool String::operator>=(const String& string) const {
  return string_ >= string.string_;
}

bool String::operator==(const String& string) const {
  return string_ == string.string_;
}

bool String::operator!=(const String& string) const {
  return string_ != string.string_;
}

std::ostream& operator<<(std::ostream& os, const String& string) {
  os << string.string_;
  return os;
}