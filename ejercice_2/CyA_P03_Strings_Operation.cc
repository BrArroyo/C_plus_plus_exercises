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
// Referencias:
// Enlaces de interés
//    https://www.cplusplus.com/reference/vector/vector/
//    https://youtu.be/GaqgqQL3wnQ
//    https://makefiletutorial.com/
//    https://google.github.io/styleguide/cppguide.html
//    https://en.wikipedia.org/wiki/Pragma_once
//    http://www.cplusplus.com/reference/set/set/
//    https://thispointer.com/stdset-tutorial-part-1-set-usage-details-with-default-sorting-criteria/
//    https://programacionenc.net/index.php?option=com_content&view=article&id=72:sobrecarga-de-operadores-en-c&catid=37:programacion-cc
//
// Archivo cya-P03-Strings_Operation.cc: programa cliente.
//    Programa que realiza operaciones con cadenas sobre un determinado
//    alfabeto, los símbolos, alfabeto y cadena son extraidos de un fichero de
//    texto y los resultados introducidos en otro fichero
//
// Historial de revisiones
//   08/10/2021 - Creación (primera versión) del código
//   09/10/2021 - Desarrollo del código fuente
//   10/10/2021 - Desarrollo de las funciones de las clases Chain
//   11/10/2021 - Desarrollo del código fuente
//   12/10/2021 - Primera versión del código terminado y comentado
//   16/10/2021 - Adaptación para la tercera práctica

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "symbol.h"
#include "alphabet.h"
#include "chain.h"
#include "language.h"

void helpProgram(char *program);
void errorArgument(char *program);
void readFile(std::vector<std::string> &fileContent, std::string file);
void writeFile(std::string result, std::string file);
void firstOpenFile(std::string file);
void divideString(std::string line, std::vector<std::string> &aux);
void creationSymbols(std::vector<std::string> &aux, Symbol &symbol, std::vector<Symbol> &symbols);
void creationSymbols(std::string chain, Symbol &symbol, std::vector<Symbol> &symbols);
void prepareChain(std::vector<std::string> &aux, std::string &temporalChain);
bool findCoincidenceSymbols(std::vector<Symbol> &symbols, std::string auxSymbol);
void optionOpcode(Chain &chain, int opcode, std::string file);

// Función Principal del programa
int main(int argc, char *argv[]) {
  std::vector<std::string> fileContent, aux;
  std::vector<Symbol> symbols;
  std::string help, filein, fileout, temporalChain;
  int opcode;
  Symbol symbol, secondSymbol;
  Alphabet alphabet, secondAlphabet;
  Chain chain, secondChain;
  
  // Comprobamos los distintos casos de la parametrización del programa
  switch (argc) {  
    case 2:
      help = argv[1]; 
      if (help == "-h" || help == "--help") {
        helpProgram(argv[0]);
        return 0;
      } else {
        errorArgument(argv[0]);
        return 1;
      }      
    case 4:
      filein = argv[1];
      fileout = argv[2];
      opcode = atoi(argv[3]);
      break;
    default:
      errorArgument(argv[0]);
      return 1;        
  }

  std::cout << "Bienvenida/o al programa de la práctica 2 de la asignatura de CyA" << std::endl;
  
  readFile(fileContent, filein);
  firstOpenFile(fileout);
  
  // Para cada linea del fichero de entrada, creamos los simbolos, su alfabeto y
  // su cadena para luego mostrarlas por el fichero de salida
  int max = fileContent.size();
  for (int i = 0; i < max; i++) {
    aux.clear();
    symbols.clear();
    divideString(fileContent[i], aux);
    creationSymbols(aux, symbol, symbols);
    prepareChain(aux, temporalChain);
    alphabet.setAlphabet(symbols);
    alphabet.createChain(temporalChain, chain);
    optionOpcode(chain, opcode, fileout);
  } 
  
  std::cout << "Programa finalizado, compruebe los resultados en su fichero de salida" << std::endl;
  return 0;
}

// Función help
void helpProgram(char *program) {
  std::cout << "Para poder ejecutar el programa correctamente es necesario "
               "pasarle por parametro el fichero de entrada, el fichero de salida"
               ", y un opcode. Por ejemplo: "  << std::endl; 
  std::cout << program << " filein.txt fileout.txt opcode" << std::endl; 
  std::cout << "Los opcodes disponibles son: " << std::endl;
  std::cout << "1: Obtener la longitud de las cadenas de entrada" << std::endl;
  std::cout << "2: Obtener la inversa de las cadenas de entrada " << std::endl;
  std::cout << "3: Obtener los prefijos de las cadenas de entrada" << std::endl;
  std::cout << "4: Obtener los sufijos de las cadenas de entrada" << std::endl;
  std::cout << "5: Obtener las subcadenas de las cadenas de entrada" << std::endl;
  std::cout << "6: Comparación de cadenas" << std::endl;
  std::cout << "7: Concatenación de cadenas" << std::endl;
  std::cout << "8: Potencia de cadenas" << std::endl;
}

// Función error para los argumentos
void errorArgument(char *program) {
  std::cout << "El número de parametros pasados no es el adecuado, ejecuta " 
            << program << " [-h|--help] para más información" << std::endl << std::endl;
}

// Función que abre y lee un fichero
void readFile(std::vector<std::string> &fileContent, std::string file) {
  std::ifstream filein;
  filein.open(file, std::ios::in);

  if (filein.fail()) {
    std::cout << "No se pudo abrir el archivo" << std::endl;
    exit(1); 
  }

  while (!filein.eof()) {
    std::string aux;
    getline(filein, aux);
    fileContent.push_back(aux);    
  }

  filein.close();
}

// Función que divide un string en un vector tomando en cuenta espacios
void divideString(std::string line , std::vector<std::string> &aux) {
  std::istringstream totalString(line);
  std::string part;

  while (!totalString.eof()) {
    totalString >> part;
    aux.push_back(part);
  }
}

// Función que rellena un vector de simbolos
void creationSymbols(std::vector<std::string> &aux, Symbol &symbol, std::vector<Symbol> &symbols) {
  if (aux.size() == 1) {
    std::string auxChain = aux[0];
    std::string auxSymbol;
    int max = aux[0].length();
    for (int i = 0; i < max; i++) {
      auxSymbol = auxChain[i];
      if (!findCoincidenceSymbols(symbols, auxSymbol)) {
        symbol.setSymbol(auxSymbol);
        symbols.push_back(symbol);
      }
    }
  } else {
    int max = aux.size() - 1;
    for (int i = 0; i < max; i++) {
      if (!findCoincidenceSymbols(symbols, aux[i])) {
        symbol.setSymbol(aux[i]);
        symbols.push_back(symbol);
      }
    }
  }
}

// Función que rellena un vector de simbolos
void creationSymbols(std::string chain, Symbol &symbol, std::vector<Symbol> &symbols) {
  std::string auxChain = chain;
  std::string auxSymbol;
  int max = chain.length();
  for (int i = 0; i < max; i++) {
    auxSymbol = auxChain[i];
    if (!findCoincidenceSymbols(symbols, auxSymbol)) {
      symbol.setSymbol(auxSymbol);
      symbols.push_back(symbol);
    }
  }
}

// Función que encuentra coincidencias de simbolos
bool findCoincidenceSymbols(std::vector<Symbol> &symbols, std::string auxSymbol) {
  int max = symbols.size();
  for (int i = 0; i < max; i++) {
    if (symbols[i].getSymbol() == auxSymbol)
      return true;
  }
  return false;
}

// Funcion que crea un string temporal con la cadena correspondiente
void prepareChain(std::vector<std::string> &aux, std::string &temporalChain) {
  if (aux.size() == 1)
    temporalChain = aux[0];
  else 
    temporalChain = aux[aux.size() - 1];
}

// Menú opcode
void optionOpcode(Chain &chain, int opcode, std::string file) {
  std::string result = "";
  std::string temporalChain, temporalExponentiation;
  int exponentiation;
  std::vector<Symbol> symbols;
  Symbol symbol;
  Alphabet alphabet;
  Chain secondChain;
  Language language;
  switch (opcode) {  
    case 1:
      result = chain.chainLenght();
      writeFile(result, file);
      break;
    case 2:
      result = chain.chainReverse();
      writeFile(result, file);
      break;
    case 3:
      chain.chainPrefix(language);
      result = language.writeLanguage();
      writeFile(result, file);
      break;
    case 4:
      chain.chainSufix(language);
      result = language.writeLanguage();
      writeFile(result, file);
      break;
    case 5:
      chain.chainSubchains(language);
      result = language.writeLanguage();
      writeFile(result, file);
      break;
    case 6:
      std::cout << "Introduce la cadena con la que hacer la comparación: ";
      std::cin >> temporalChain;
      creationSymbols(temporalChain, symbol, symbols);
      alphabet.setAlphabet(symbols);
      alphabet.createChain(temporalChain, secondChain);
      result = chain == secondChain;
      writeFile(result, file);
      break;
    case 7:
      std::cout << "Introduce la cadena con la que hacer la concatenación: ";
      std::cin >> temporalChain;
      creationSymbols(temporalChain, symbol, symbols);
      alphabet.setAlphabet(symbols);
      alphabet.createChain(temporalChain, secondChain);
      result = chain + secondChain;
      writeFile(result, file);
      break;
    case 8:
      std::cout << "Introduce la potencia que se quiera utilizar: ";
      std::cin >> temporalExponentiation;
      exponentiation = stoi(temporalExponentiation);
      result = chain ^ exponentiation;
      writeFile(result, file);
      break;
    default:
      break;        
  }
}

// Función para escribir en un fichero los resultados
void writeFile(std::string result, std::string file) {
  std::ofstream fileout;
  fileout.open(file, std::ios::app); //Abre el archivo para escribir
  if (fileout.fail()) {
    std::cout << "No se pudo abrir el archivo" << std::endl;
    exit(1); 
  }
  
  fileout << result << "\n";
  fileout.close(); 
}

// Abre el fichero de salida y lo prepara para las operaciones
void firstOpenFile(std::string file) {
  std::ofstream fileout;
  fileout.open(file, std::ios::out); //Abre el archivo para escribir
  if (fileout.fail()) {
    std::cout << "No se pudo abrir el archivo" << std::endl;
    exit(1); 
  }
  
  fileout << "";
  fileout.close(); 
}
