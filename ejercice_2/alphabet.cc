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
//   16/10/2021 - Adaptación para la tercera práctica

#include "alphabet.h"

// Constructor por defecto
Alphabet::Alphabet() {}

// Constructor parametrizado
Alphabet::Alphabet(std::set<Symbol> alphabet) {
  //alphabet_ = alphabet;
}

// Destructor
Alphabet::~Alphabet() {}

// Setter del atributo alphabet_
void Alphabet::setAlphabet(std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}

// Setter del atributo alphabet_
void Alphabet::setAlphabet(std::vector<Symbol> alphabet) {
  int limit = alphabet.size();
  
  for (int i = 0; i < limit; i++) {
    alphabet_.insert(alphabet[i]);
  }
}

// Getter del atributo alphabet_
std::set<Symbol> Alphabet::getAlphabet() const {
  return alphabet_;
}

// Función que permite la creación de la cadena a partir del alfabeto
void Alphabet::createChain(std::string temporalChain, Chain &chain) {
  Symbol symbol(""), aux("");
  std::vector<Symbol> result;
  std::set<Symbol>::iterator it;
  int max1 = temporalChain.size();
  
  for (int i = 0; i < max1; i++) {
    symbol.setSymbol(symbol.getSymbol() + temporalChain[i]);
    for (it = alphabet_.begin(); it != alphabet_.end(); it++) {
      aux = *it;
      if (symbol.getSymbol() == aux.getSymbol()) {
        result.push_back(symbol);
        symbol.setSymbol("");
      }
    }
  }
  
  chain.setChain(result);
}