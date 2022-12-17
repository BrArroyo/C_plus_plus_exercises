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
//    Programa que define la clase language, la cual representa un lenguaje
//
// Referencias:
// Enlaces de interés
//    http://www.cplusplus.com/reference/set/set/
//    https://thispointer.com/stdset-tutorial-part-1-set-usage-details-with-default-sorting-criteria/
//    https://programacionenc.net/index.php?option=com_content&view=article&id=72:sobrecarga-de-operadores-en-c&catid=37:programacion-cc
//    
// Historial de revisiones
//   17/10/2021 - Creación (primera versión) del código

#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <string>

class Language {
  public:
    // Constructores y destructor
    Language();
    Language(std::set<std::string> language);
    ~Language();
    
    // Setters y Getters
    void setLanguage(std::set<std::string> language);
    std::set<std::string> getLanguage() const;

    void insertChain(std::string chain);
  
    std::string writeLanguage();

  private:
    std::set<std::string> language_;
};