// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
//
// Autor: Bruno Lorenzo Arroyo Pedraza
// Correo: alu0101123677@ull.edu.es
// Fecha: 17/10/2021
//
// Archivo language.h: clase language.
//    Programa que define las funciones de la clase Language
//
// Referencias:
// Enlaces de interés
//    http://www.cplusplus.com/reference/set/set/
//    https://thispointer.com/stdset-tutorial-part-1-set-usage-details-with-default-sorting-criteria/
//    https://programacionenc.net/index.php?option=com_content&view=article&id=72:sobrecarga-de-operadores-en-c&catid=37:programacion-cc
//    
// Historial de revisiones
//   17/10/2021 - Creación (primera versión) del código

#include "language.h"

// Constructor por defecto
Language::Language() {}

// Constructor Parametrizado
Language::Language(std::set<std::string> language) {
  language_ = language;
}

// Destructor
Language::~Language() {} 

// Setter del atributo language_
void Language::setLanguage(std::set<std::string> language) {
  language_ = language;
}

// Getter del atributo language_
std::set<std::string> Language::getLanguage() const {
  return language_;
}

void Language::insertChain(std::string chain) {
  language_.insert(chain);
}

// Función que compone para imprimir un lenguaje
std::string Language::writeLanguage() {
  std::string result = "{";
  std::set<std::string>::iterator it;
  
  for (it = language_.begin(); it != language_.end(); it++) {
    result = result + *it;
    result = result + ", ";
  }

  return result = result + "}";
}

