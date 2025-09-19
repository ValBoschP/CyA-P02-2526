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

#include <algorithm>

#include "string.h"

/**
 * @brief Constructs a String object with the given string and alphabet.
 *
 * Initializes the String object by storing the provided string and populating
 * the internal alphabet with the symbols from the given alphabet string.
 *
 * @param string The string to be stored in the String object.
 * @param alphabet The string representing the set of valid symbols (alphabet).
 */
String::String(const std::string& string, const std::string& alphabet) : string_(string) {
  for (const auto& symbol : alphabet) {
    alphabet_.AddSymbol(symbol);
  }
}

/**
 * @brief Returns the length of the string.
 *
 * If the internal string is equal to "&", it is considered to represent
 * the empty string (epsilon) and the function returns 0. Otherwise,
 * it returns the actual length of the string.
 *
 * @return The length of the string, or 0 if the string is "&".
 */
int String::Length() const {
  if (string_ == "&") return 0;
  return string_.length();
}

/**
 * @brief Returns the inverse (reversed) version of the current String object.
 *
 * If the string is empty or equals "&", the method returns a String object containing "&".
 * Otherwise, it returns a new String object with the characters in reverse order.
 *
 * @return String The reversed String object or "&" if the original string is empty or "&".
 */
String String::Inverse() const {
  if (string_.empty() || string_ == "&") return String("&");
  std::string reversed_string(string_.rbegin(), string_.rend());
  return String(reversed_string);
}

/**
 * @brief Returns the inverse (reversed) version of the current string.
 *
 * If the string is empty or equals "&", the method returns "&".
 * Otherwise, it returns a new string with the characters in reverse order.
 *
 * @return std::string The reversed string or "&" for empty/"&" input.
 */
std::string String::InverseString() const {
  if (string_.empty() || string_ == "&") return "&";
  return std::string(string_.rbegin(), string_.rend());
}

/**
 * @brief Generates all prefixes of the current string, including the empty string.
 *
 * This method returns a set containing all possible prefixes of the string
 * represented by this object. If the string is the special symbol "&" (representing
 * the empty string), the result will contain only the empty string ("").
 * Otherwise, the set will include "&" (as the empty string) and all non-empty prefixes.
 *
 * @return std::set<std::string> Set of all prefixes of the string, including the empty string.
 */
std::set<std::string> String::Prefixes() const {
  std::set<std::string> result;
  std::string prefix;
  if (string_ == "&") {
    result.insert("");
    return result;
  }
  result.insert("&");
  for (const auto& symbol : string_) {
    prefix += symbol;
    result.insert(prefix);
  }
  return result;
}

/**
 * @brief Generates all possible suffixes of the string, including the empty string.
 *
 * This method computes and returns a set containing all suffixes of the string
 * represented by this object. If the string is "&", which represents the empty string,
 * the result will contain only the empty string (""). Otherwise, the result will
 * always include "&" (representing the empty string) and all non-empty suffixes.
 *
 * @return std::set<std::string> A set containing all suffixes of the string.
 */
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

/**
 * @brief Generates all possible substrings of the current string.
 *
 * This method computes and returns a set containing every possible substring
 * (including single-character and the full string) of the string stored in this object.
 * Each substring is unique in the resulting set.
 *
 * @return std::set<std::string> A set containing all unique substrings of the string.
 */
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

/**
 * @brief Returns a new String that is the concatenation of this String repeated n times.
 *
 * If n is 0, returns the empty string represented as "&".
 *
 * @param n The number of times to repeat the string.
 * @return String The resulting String after exponentiation.
 */
String String::Power(const int n) const {
  if (n == 0) return String("&");
  std::string result;
  for (int i = 0; i < n; ++i) {
    result += string_;
  }
  return String(result, alphabet_);
}

/**
 * @brief Checks if all symbols in the string belong to the associated alphabet.
 *
 * Iterates through each symbol in the string and verifies whether it is contained
 * within the associated alphabet. Returns true if every symbol is present in the
 * alphabet; otherwise, returns false.
 *
 * @return true if the string only contains symbols from the alphabet, false otherwise.
 */
bool String::BelongsToAlphabet() const {
  for (const auto& symbol : string_) {
    if (!alphabet_.Contains(symbol)) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Compares this String object with another for lexicographical order.
 *
 * Determines if the current String object is lexicographically less than the specified String.
 *
 * @param string The String object to compare with.
 * @return true if this String is less than the given String, false otherwise.
 */
bool String::operator<(const String& string) const {
  if(Length() < string.Length()) return true;
  if(Length() == string.Length()) return string_ < string.string_;
  return false;
}

/**
 * @brief Compares this String object with another for lexicographical order.
 *
 * Determines if the current String object is lexicographically less than or equal to the specified String.
 *
 * @param string The String object to compare with.
 * @return true if this String is less than or equal to the given String, false otherwise.
 */
bool String::operator<=(const String& string) const {
  if(Length() < string.Length()) return true;
  if(Length() == string.Length()) return string_ <= string.string_;
  return false;
}

/**
 * @brief Compares this String object with another for lexicographical order.
 * 
 * Determines if the current String object is lexicographically greater than the specified String.
 *
 * @param string The String object to compare with.
 * @return true if this String is greater than the given String, false otherwise.
 */
bool String::operator>(const String& string) const {
  if(Length() > string.Length()) return true;
  if(Length() == string.Length()) return string_ > string.string_;
  return false;
}
/**
 * @brief Compares this String object with another for lexicographical order.
 *
 * Determines if the current String object is lexicographically greater than the specified String.
 *
 * @param string The String object to compare with.
 * @return true if this String is greater than the given String, false otherwise.
 */
bool String::operator>=(const String& string) const {
  if(Length() > string.Length()) return true;
  if(Length() == string.Length()) return string_ >= string.string_;
  return false;
}

/**
 * @brief Compares this String object with another for equality.
 *
 * Checks if the contents of this String are equal to the contents of the given String.
 *
 * @param string The String object to compare with.
 * @return true if both String objects have the same content, false otherwise.
 */
bool String::operator==(const String& string) const {
  return string_ == string.string_;
}

/**
 * @brief Inequality operator for the String class.
 *
 * Compares this String object with another String object for inequality.
 *
 * @param string The String object to compare with.
 * @return true if the strings are not equal, false otherwise.
 */
bool String::operator!=(const String& string) const {
  return string_ != string.string_;
}

/**
 * @brief Overloads the output stream operator for the String class.
 *
 * This function allows objects of the String class to be output to an
 * output stream (such as std::cout) by inserting the underlying string
 * representation into the stream.
 *
 * @param os The output stream to which the string will be written.
 * @param string The String object to output.
 * @return Reference to the output stream after writing the string.
 */
std::ostream& operator<<(std::ostream& os, const String& string) {
  os << string.string_;
  return os;
}