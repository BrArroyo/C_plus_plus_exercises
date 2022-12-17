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
//   16/10/2021 - Adaptación para la tercera práctica

#include "chain.h"

// Constructor por defecto
Chain::Chain() {}

// Constructor Parametrizado
Chain::Chain(std::vector<Symbol> chain) {
  chain_.resize(chain.size());
  chain_ = chain;
}

// Destructor
Chain::~Chain() {} 


// Setter del atributo chain_
void Chain::setChain(std::vector<Symbol> chain) {
  chain_.resize(chain.size());
  chain_ = chain;
}


// Getter del atributo chain_
std::vector<Symbol> Chain::getChain() const {
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
    result = result + chain_[i].getSymbol();
  }

  return result;
}


// Función que calcula los prefijos de una cadena
void Chain::chainPrefix(Language &language) {
  int limit = chain_.size();
  language.insertChain("&");
  std::string temporal_str = "";
  
  for (int i = 0; i < limit; i++) {
    temporal_str = temporal_str + chain_[i].getSymbol();
    language.insertChain(temporal_str);
  }
}


// Función que calcula los sufijos de una cadena
void Chain::chainSufix(Language &language) {
  int limit = chain_.size();
  language.insertChain("&");
  std::string temporal_str = "";
  
  for (int i = limit - 1; i >= 0; i--) {
    temporal_str = chain_[i].getSymbol() + temporal_str;
    language.insertChain(temporal_str);
  }
}


// Función que calcula las subcadenas de una cadena
void Chain::chainSubchains(Language &language) {
  int limit = chain_.size();
  language.insertChain("&");
  std::string temporal_str = "";
  
  for (int i = 0; i < limit; i++) {
    temporal_str = chain_[i].getSymbol();
    for (int j = 1 + i; j < limit; j++) {
      language.insertChain(temporal_str);
      temporal_str = temporal_str + chain_[j].getSymbol();
    }
    language.insertChain(temporal_str);
  }  
}

// Compara si una cadena es subcadena de otra
bool Chain::compareSubchains(std::string chain) {
  int limit = chain_.size();
  std::string temporal_str;
  
  
  for (int i = 0; i < limit; i++) {
    temporal_str = chain_[i].getSymbol();
    for (int j = 1 + i; j < limit; j++) {
      if (temporal_str == chain)
        return true;
      temporal_str = temporal_str + chain_[j].getSymbol();
      if (temporal_str == chain)
        return true;
    }
  }  
  return false;
}

std::string Chain::writeChain() {
  std::string result = "";
  for (int i = 0; i < chain_.size(); i++)
    result = result + chain_[i].getSymbol();
  return result;
}

// Sobrecarga del operador == para comparar cadenas
std::string Chain::operator==(const Chain secondChain) const {
  std::string result;
  Chain chainFirst(chain_), chainSecond(secondChain.getChain());

  if (chain_.size() == secondChain.getChain().size()) {
    for (int i = 0; i < chain_.size(); i++) {
      if (chain_[i].getSymbol() != secondChain.getChain()[i].getSymbol())
        return result = chainFirst.writeChain() + " != " + chainSecond.writeChain();
    }
    return result = chainFirst.writeChain() + " == " + chainSecond.writeChain();
  } else {
    if (chain_.size() > secondChain.getChain().size()) {
      if (chainFirst.compareSubchains(chainSecond.writeChain())) 
        return result = chainFirst.writeChain() + " > " + chainSecond.writeChain();
      else
        return result = chainFirst.writeChain() + " != " + chainSecond.writeChain();
    } else {
      if (chainSecond.compareSubchains(chainFirst.writeChain()))
        return result = chainFirst.writeChain() + " < " + chainSecond.writeChain();
      else
        return result = chainFirst.writeChain() + " != " + chainSecond.writeChain();
    }
  }
  
  return result = chainFirst.writeChain() + " != " + chainSecond.writeChain();

}

// Sobrecarga del operador + para concatenar cadenas
std::string Chain::operator+(const Chain secondChain) const {
  std::string result;
  Chain chainFirst(chain_), chainSecond(secondChain.getChain());
  return result = chainFirst.writeChain() + chainSecond.writeChain();
}


// Sobrecarga del operador ^ para potencias de cadenas
std::string Chain::operator^(const int exponentiation) const {
  std::string result = "";
  Chain chain(chain_);
  if (exponentiation == 0)
    return result = "&";
  else {
    for (int i = 1; i <= exponentiation; i++) {
      result = result + chain.writeChain();
    }
  }
  return result;
}








