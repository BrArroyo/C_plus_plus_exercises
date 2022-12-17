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
// Archivo alphabet.h: clase alphabet.
//    Programa que define la clase Alphabet, la cual representa
//    un alfabeto formado por símbolos
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

#pragma once
#include <iostream>
#include <vector>
#include <set>

#include "symbol.h"
#include "chain.h"

class Alphabet {
  public:
    // Constructores y destructores
    Alphabet();
    Alphabet(std::set<Symbol> alphabet);
    ~Alphabet();
    
    // Setters y getters
    void setAlphabet(std::set<Symbol> alphabet);
    void setAlphabet(std::vector<Symbol> alphabet);
    std::set<Symbol> getAlphabet() const;
    
    // Función que permite la creación de la cadena a partir del alfabeto
    void createChain(std::string temporalChain, Chain &chain);

  private:
    std::set<Symbol> alphabet_;
};