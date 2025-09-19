/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 19/09/2025
 * Archivo main.cc: programa principal.
 * Contiene la función main del proyecto, gestiona la entrada y salida de ficheros
 * y aplica las operaciones solicitadas sobre las cadenas.
 * Referencias:
 * Historial de revisiones:
 * 19/09/2025 - Creación (primera versión) del código
 */

#include "file.h"
#include "menu.h"
#include "language.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Main program that manages file input and output and applies the requested operations on the strings.
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 */
int main(int argc, char* argv[]) {
    Program(argc, argv);
    return 0;
}

