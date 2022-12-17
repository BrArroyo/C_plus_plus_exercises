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
// Archivo chain.cc: clase chain.
//    Programa que define los métodos de la clase Chain
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

#include "chain.h"

// Constructor por defecto
Chain::Chain() {}

// Constructor Parametrizado
Chain::Chain(std::vector<std::string> chain) {
  chain_.resize(chain.size());
  chain_ = chain;
}

// Destructor
Chain::~Chain() {} 


// Setter del atributo chain_
void Chain::setChain(std::vector<std::string> chain) {
  chain_.resize(chain.size());
  chain_ = chain;
}


// Getter del atributo chain_
std::vector<std::string> Chain::getChain() const {
  return chain_;
}


// Función que calcula la longitud de una cadena
std::string Chain::chainLenght() {
  std::string result(std::to_string(chain_.size())); 
  return result;
}


// Función que calcula la reversa de una cadena
std::string Chain::chainReverse() {
  int limit = chain_.size();
  std::string result = "";
  
  for (int i = limit - 1; i >= 0; i--) {
    result = result + chain_[i];
  }

  return result;
}


// Función que calcula los prefijos de una cadena
std::string Chain::chainPrefix() {
  int limit = chain_.size();
  std::string result = "&";
  std::string temporal_str = "";
  
  for (int i = 0; i < limit; i++) {
    result = result + " ";
    temporal_str = temporal_str + chain_[i];
    result = result + temporal_str;
  }

  return result;
}


// Función que calcula los sufijos de una cadena
std::string Chain::chainSufix() {
  int limit = chain_.size();
  std::string result = "&";
  std::string temporal_str = "";
  
  for (int i = limit - 1; i >= 0; i--) {
    result = result + " ";
    temporal_str = chain_[i] + temporal_str;
    result = result + temporal_str;
  }

  return result;
}


// Función que calcula las subcadenas de una cadena
std::string Chain::chainSubchains() {
  int limit = chain_.size();
  std::string result = "&";
  std::string temporal_str = "";
  
  for (int i = 0; i < limit; i++) {
    temporal_str = chain_[i];
    for (int j = 1 + i; j <= limit; j++) {
      result = result + " ";
      result = result + temporal_str;
      temporal_str = temporal_str + chain_[j];
    }
  }  

  return result;
}

