// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
//
// Autor: Bruno Lorenzo Arroyo Pedraza
// Correo: alu0101123677@ull.edu.es
// Fecha: 09/10/2021
//
// Archivo alphabet.cc: clase alphabet.
//    Programa que define los métodos de la clase Alphabet
//    
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

#include "alphabet.h"

// Constructor por defecto
Alphabet::Alphabet() {}

// Constructor parametrizado
Alphabet::Alphabet(std::vector<Symbol> alphabet) {
  alphabet_.resize(alphabet.size());
  alphabet_ = alphabet;
}

// Destructor
Alphabet::~Alphabet() {}

// Setter del atributo alphabet_
void Alphabet::setAlphabet(std::vector<Symbol> alphabet) {
  alphabet_.resize(alphabet.size());
  alphabet_ = alphabet;
}

// Getter del atributo alphabet_
std::vector<Symbol> Alphabet::getAlphabet() const {
  return alphabet_;
}

// Función que permite la creación de la cadena a partir del alfabeto
void Alphabet::createChain(std::string temporalChain, Chain &chain) {
  std::string aux = "";
  std::vector<std::string> result;
  int max1 = temporalChain.size(), max2 = alphabet_.size();
  
  for (int i = 0; i < max1; i++) {
    aux = aux + temporalChain[i];
    for (int j = 0; j < max2; j++) {
      if (aux == alphabet_[j].getSymbol()) {
        result.push_back(aux);
        aux = "";
      }
    }
  }
  
  chain.setChain(result);
}