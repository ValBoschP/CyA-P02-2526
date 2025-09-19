/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 19/09/2025
 * Archivo menu.cc: implementación de funciones de procesamiento y de utilidades para la función principal.
 * Este archivo contiene la implementación de las funciones de procesamiento que
 * ejecutan las operaciones.
 * Referencias:
 * Historial de revisiones:
 * 19/09/2025 - Creación (primera versión) del código
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "menu.h"
#include "string.h"

/**
 * @brief Shows help about the usage of the program.
 */
void ShowHelp() {
  std::cout << "Usage: ./p02_strings filein.txt fileout.txt opcode\n";
  std::cout << "Available opcodes:\n";
  std::cout << "1 - Alphabet\n";
  std::cout << "2 - Length\n";
  std::cout << "3 - Reverse\n";
  std::cout << "4 - Prefixes\n";
  std::cout << "5 - Suffixes\n";
  // std::cout << "--- OTHERS ---\n";
  // std::cout << "7 - Palindrome\n";
  // std::cout << "8 - Power\n";
  // std::cout << "9 - Belongs to Alphabet\n";
  // std::cout << "10 - Substrings\n";
}

/**
 * @brief Validates the input parameters of the program.
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @return true: if the parameters are valid.
 * @return false: if the parameters are not valid.
 */
bool ValidateParameters(int argc, char *argv[]) {
  if (argc == 2 &&
      (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
    ShowHelp();
    return false;
  }
  if (argc != 4) {
    std::cerr << "Usage: ./p02_strings filein.txt fileout.txt opcode"
              << std::endl;
    std::cerr << "Try './p02_strings --help' for more information."
              << std::endl;
    return false;
  }
  std::string opcode_str = argv[3];
  if (!std::all_of(opcode_str.begin(), opcode_str.end(), ::isdigit)) {
    std::cerr << "Error: Opcode must be a number." << std::endl;
    return false;
  }
  return true;
}

/**
 * @brief Main program that manages file input/output and applies the requested operations on the strings.
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 */
void Program(int argc, char *argv[]) {
  if (!ValidateParameters(argc, argv)) exit(1);

  std::string input_file = argv[1];
  std::string output_file = argv[2];
  int opcode = std::stoi(argv[3]);

  std::vector<String> strings = ReadInputFile(input_file);
  std::vector<std::string> results = ProcessStrings(strings, opcode);
  WriteOutputFile(output_file, results);
}

/**
 * @brief Gets the alphabet from the characters of the string.
 * @param string Object of type `String`.
 * @return std::string String representation of the alphabet formed by the string.
 */
std::string ProcessAlphabet(const String &string) {
  if (!string.BelongsToAlphabet())
    return "The string contains symbols that do not belong to the alphabet.";
  return string.GetAlphabet().GetStringAlphabet();
}

/**
 * @brief Gets the length of the string.
 * @param string Object of type `String`.
 * @return std::string Length of the string as a string.
 */
std::string ProcessLength(const String &string) {
  return std::to_string(string.Length());
}

/**
 * @brief Gets the reversed string.
 * @param string Object of type `String`.
 * @return std::string The string in reverse order.
 */
std::string ProcessReverse(const String &string) {
  return string.InverseString();
}

/**
 * @brief Gets all prefixes of the string.
 * @param string Object of type `String`.
 * @return std::string String representation of the prefixes.
 */
std::string ProcessPrefixes(const String &string) {
  std::stringstream result;
  Language prefix_lang(string.Prefixes());
  result << prefix_lang;
  return result.str();
}

/**
 * @brief Gets all suffixes of the string.
 * @param string Object of type `String`.
 * @return std::string String representation of the suffixes.
 */
std::string ProcessSuffixes(const String &string) {
  std::stringstream result;
  Language suffix_lang(string.Suffixes());
  result << suffix_lang;
  return result.str();
}

/**
 * @brief Checks if the string is a palindrome.
 * @param string Object of type `String`.
 * @return std::string Message indicating if it is a palindrome or not.
 */
std::string ProcessPalindrome(const String &string) {
  std::string reversed = string.InverseString();
  if (string.GetString() == reversed) {
    return "Is palindrome";
  } else {
    return "Is not palindrome";
  }
}

/**
 * @brief Generates the power of the string a given number of times.
 * @param string Object of type `String`.
 * @param n_times Number of times the string should be repeated.
 * @return std::string Resulting string of the power.
 */
std::string ProcessRepetitions(const String &string, int n_times) {
  std::stringstream result;
  String result_string(string.Power(n_times));
  result << result_string;
  return result.str();
}

/**
 * @brief Checks if all characters of the string belong to the alphabet.
 * @param string Object of type `String`.
 * @return std::string Message indicating if it belongs to the alphabet or not.
 */
std::string BelongsToAlphabet(const String &string) {
  std::string alphabet = string.GetAlphabet().GetStringAlphabet();
  for (const auto &character : string.GetStringString()) {
    if (alphabet.find(character) == std::string::npos) {
      return "Does not belong to the Alphabet";
    }
  }
  return "Belongs to the Alphabet";
}

/**
 * @brief Gets all substrings of the string.
 * @param string Object of type `String`.
 * @return std::string String representation of the substrings.
 */
std::string ProcessSubstrings(const String &string) {
  std::stringstream result;
  Language substrings_lang(string.Substrings());
  result << substrings_lang;
  return result.str();
}

/**
 * @brief Processes a vector of strings according to the specified opcode.
 * @param strings Vector of `String` objects.
 * @param opcode Opcode to select the operation to perform.
 * @return std::vector<std::string> Results of the processes.
 */
std::vector<std::string> ProcessStrings(const std::vector<String> &strings,
                                        int opcode) {
  std::vector<std::string> results;
  int n_power = 0;
  int string_counter = 1;
  String concat_string(strings[string_counter]);
  for (const auto &string : strings) {
    switch (opcode) {
      case 1:  // GET ALPHABET
        if (string.GetAlphabet().IsEmpty()) {
          results.push_back(ProcessAlphabet(string));
        } else {
          results.push_back(ProcessAlphabet(string));
        }
        break;
      case 2:  // GET LENGTH
        results.push_back(ProcessLength(string));
        break;
      case 3:  // GET REVERSE
        results.push_back(ProcessReverse(string));
        break;
      case 4:  // GET PREFIXES
        results.push_back(ProcessPrefixes(string));
        break;
      case 5:  // GET SUFFIXES
        results.push_back(ProcessSuffixes(string));
        break;
      /*
      case 7:  // CHECK IF PALINDROME
        results.push_back(ProcessPalindrome(string));
        break;
      case 8:  // GET POWER N TIMES
        std::cout << "Enter the power (n): ";
        std::cin >> n_power;
        results.push_back(ProcessRepetitions(string, n_power));
        break;
      case 9:  // CHECK IF STRING BELONGS TO ALPHABET
        results.push_back(BelongsToAlphabet(string));
        break;
      case 10:  // GET SUBSTRINGS
        results.push_back(ProcessSubstrings(string));
        break;
      // -- ADD MORE IF NEEDED --
      */
      default:
        std::cerr << "Invalid opcode." << std::endl;
        exit(1);
    }
  }
  return results;
}
