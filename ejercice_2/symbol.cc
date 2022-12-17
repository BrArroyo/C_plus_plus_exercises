// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
//
// Autor: Bruno Lorenzo Arroyo Pedraza
// Correo: alu0101123677@ull.edu.es
// Fecha: 09/10/2021
//
// Archivo symbol.cc: clase symbol.
//    Programa que define los métodos de la clase Symbol
//
// Referencias:
// Enlaces de interés
//    https://www.cplusplus.com/reference/vector/vector/
//    https://youtu.be/GaqgqQL3wnQ
//    https://makefiletutorial.com/
//    https://google.github.io/styleguide/cppguide.html
//    https://en.wikipedia.org/wiki/Pragma_once
//    
// Historial de revisiones
//   08/10/2021 - Creación (primera versión) del código
//   09/10/2021 - Desarrollo del código fuente
//   10/10/2021 - Desarrollo de las funciones de las clases Chain
//   11/10/2021 - Desarrollo del código fuente
//   12/10/2021 - Primera versión del código terminado y comentado

#include "symbol.h"

// Constructor por defecto
Symbol::Symbol(){}

// Constructor parametrizado
Symbol::Symbol(std::string symbol) {
  symbol_ = symbol;
}

// Destructor
Symbol::~Symbol() {}

// Setter del atributo symbol_
void Symbol::setSymbol(std::string symbol) {
  symbol_ = symbol;
}

// Getter del atributo symbol_
std::string Symbol::getSymbol() const {
  return symbol_;
}

bool Symbol::operator<(const Symbol &right) const {
  return symbol_ < right.getSymbol();
}