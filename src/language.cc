#include "language.h"
#include "string.h"

#include <iostream>

/**
 * @brief Constructor that initializes the language from a set of strings.
 * @param strings Set of strings.
 * @return Language Object of type Language.
 */
Language::Language(const std::set<std::string>& strings) {
  for (const auto& str : strings) {
    strings_.insert(String(str));
  }
}

/**
 * @brief Adds a string to the language.
 * @param str String to add.
 */
void Language::AddString(const String& str) {
  strings_.insert(str);
}

/**
 * @brief Adds a string to the language.
 * @param str String to add.
 */
void Language::AddString(const std::string& str) {
  strings_.insert(String(str));
}

/**
 * @brief Output stream operator overload for the Language class.
 * @param os Output stream where the language representation will be printed.
 * @param language Language object to print.
 * @return std::ostream& Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Language& language) {
  if (language.IsEmpty()) {
    os << "{ }";
    return os;
  }
  os << "{";
  for (const auto& str : language.GetStrings()) {
    if (str == *language.GetStrings().rbegin()) {
      os << str;
      break;
    }
    os << str << ", ";
  }
  os << "}";
  return os;
}

/**
 * @brief Performs the union of two languages.
 * @param language Language to perform the union with.
 * @return Language Resulting language from the union.
 */
Language Language::Union(const Language& language) {
  std::set<String> result = this->GetStrings();
  for (const auto& str : language.GetStrings()) {
    result.insert(str);
  }
  return Language(result);
}

/**
 * @brief Performs the intersection of two languages.
 * @param language Language to perform the intersection with.
 * @return Language Resulting language from the intersection.
 */
Language Language::Intersection(const Language& language) {
  std::set<String> result;
  for (const auto& str : this->GetStrings()) {
    if (language.GetStrings().count(str)) {
      result.insert(str);
    }
  }
  return Language(result);
}

/**
 * @brief Performs the difference of two languages.
 * @param language Language to perform the difference with.
 * @return Language Resulting language from the difference.
 */
Language Language::Difference(const Language& language) {
  std::set<String> result;
  for (const auto& str : this->GetStrings()) {
    if (!language.GetStrings().count(str)) {
      result.insert(str);
    }
  }
  return Language(result);
}

/**
 * @brief Performs the concatenation of two languages.
 * @param language Language to perform the concatenation with.
 * @return  Language Resulting language from the concatenation.
 */
Language Language::Concatenation(const Language& language) {
  std::set<String> result;
  for (const auto& str1 : this->GetStrings()) {
    for (const auto& str2 : language.GetStrings()) {
      result.insert(String(str1.GetStringString() + str2.GetStringString()));
    }
  }
  return Language(result);
}
