/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 19/09/2025
 * Archivo file.h: Declaración de funciones para archivos.
 * Este archivo contiene las declaraciones de las funciones que realizan la lectura y escritura
 * de archivos de entrada y salida, respectivamente.
 * Referencias:
 * Historial de revisiones:
 * 19/09/2025 - Creación (primera versión) del código
 */

#ifndef FILE_H
#define FILE_H

#include "string.h"

#include <string>
#include <vector>

bool IsPrintableASCII(const std::string& str);
std::vector<String> ReadInputFile(const std::string& input_file);
void WriteOutputFile(const std::string& output_file,
           const std::vector<std::string>& results);

#endif  // FILE_H