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
// Archivo chain.h: clase chain.
//    Programa que define la clase Symbol, la cual representa una cadena
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
#include <string>

#include "symbol.h"
#include "language.h"

class Chain {
  public:
    // Constructores y destructor
    Chain();
    Chain(std::vector<Symbol> chain);
    ~Chain();
    
    // Setters y Getters
    void setChain(std::vector<Symbol> chain);
    std::vector<Symbol> getChain() const;
    
    // Operaciones de una cadena
    std::string chainLenght();
    std::string chainReverse();
    void chainPrefix(Language &language);
    void chainSufix(Language &language);
    void chainSubchains(Language &language);

    // Sobrecarga de operadores
    std::string operator==(const Chain secondChain) const;
    std::string operator+(const Chain secondChain) const;
    std::string operator^(const int exponentiation) const;

    bool compareSubchains(std::string chain);
    std::string writeChain();

  private:
    std::vector<Symbol> chain_;
};