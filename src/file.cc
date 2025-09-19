/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 18/09/2024
 * Archivo file.cc: Implementación de funciones para archivos.
 * Este archivo contiene la implementación de las funciones que realizan la lectura y escritura.
 * Referencias:
 * Historial de revisiones:
 * 18/09/2024 - Creación (primera versión) del código
 */


#include "file.h"

#include <fstream>
#include <iostream>

const char SPACE = ' ';

/**
 * @brief Checks if a string is printable ASCII.
 * @param str String to check.
 * @return true If the string is printable ASCII.
 * @return false If the string is not printable ASCII.
 */
bool IsASCIIString(const std::string& str) {
  for (char ch : str) {
    if (!std::isprint(static_cast<unsigned char>(ch))) return false;
  }
  return true;
}

/**
 * @brief Reads an input file and creates a vector of `String` objects.
 * @param input_file Path to the input file.
 * @return std::vector<String> Vector of `String` objects created from the file.
 */
std::vector<String> ReadInputFile(const std::string& input_file) {
  std::ifstream infile(input_file);
  std::vector<String> cadenas;
  std::string line;
  int string_counter = 1;
  while (std::getline(infile, line)) {
    int space = line.find(SPACE);
    std::string str = line.substr(0, space);
    std::string alphabet = line.substr(space + 1);
    str.erase(std::remove(str.begin(), str.end(), '&'), str.end());
    if (!IsPrintableASCII(str)) {
      std::cerr << "WARNING: String " << string_counter << " is not printable ASCII." << std::endl;
      std::cerr << "The string has been omitted." << std::endl;
      continue;
    }
    cadenas.emplace_back(String(str, alphabet));
    ++string_counter;
  }
  return cadenas;
}

/**
 * @brief Writes the results to an output file.
 * @param output_file Path to the output file.
 * @param results Vector of strings containing the results to write to the file.
 */
void WriteOutputFile(const std::string& output_file,
                     const std::vector<std::string>& results) {
  std::ofstream outfile(output_file);
  for (const auto& line : results) {
    outfile << line << std::endl;
  }
}