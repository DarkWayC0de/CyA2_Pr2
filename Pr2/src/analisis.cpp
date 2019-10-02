//
//Archivo: Analisis.cpp
//Fecha: 26/9/2019
//Autor: Diego Cruz Rodríguez
//Titulo: Prácica 2 de Computabilidad y Algoritmia
//Uso de archivo: Implentacion de la clase Analisis
//

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "funciones.h"
#include "analisis.h" 

Analisis::Analisis() : parentesis_(0), llaves_(0), corchetes_(0) {
  std::ifstream readfile("data/file1.dat");
  if (readfile.is_open()) {
    while (!readfile.eof()) {
      std::string linea;
      std::getline(readfile,linea);
      std::for_each(linea.begin(), linea.end(), [](char & c){
        c = ::tolower(c);
      });
      this -> Analisis_[0].insert(linea);
    }
  } else {
    std::cout << "Error, no se ha podido aceder y cargar el" <<
                 "archivo de datos de las plabras especiales.\n";
    exit(2);
  }

  this -> Analisis_[5].insert("+");
  this -> Analisis_[5].insert("-");
  this -> Analisis_[5].insert("*");
  this -> Analisis_[5].insert("/");
  this -> Analisis_[5].insert("=");
  this -> Analisis_[5].insert("<");
  this -> Analisis_[5].insert(">");
  this -> Analisis_[3].insert("<=");
  this -> Analisis_[3].insert(">=");
  this -> Analisis_[3].insert("!=");
  this -> Analisis_[4].insert("(");
  this -> Analisis_[4].insert(")");
  this -> Analisis_[4].insert("[");
  this -> Analisis_[4].insert("]");
  this -> Analisis_[4].insert(".");
  this -> Analisis_[4].insert("{");
  this -> Analisis_[4].insert("}");
  this -> Analisis_[4].insert(";");
  this -> Analisis_[4].insert(",");
  this -> Analisis_[2].insert("1");
  this -> Analisis_[2].insert("2");
  this -> Analisis_[2].insert("3");
  this -> Analisis_[2].insert("4");
  this -> Analisis_[2].insert("5");
  this -> Analisis_[2].insert("6");
  this -> Analisis_[2].insert("7");
  this -> Analisis_[2].insert("8");
  this -> Analisis_[2].insert("9");
  this -> Analisis_[2].insert("0");
  for (char i = 'A'; i < '{' ; i++) {
    if (i=='[') {
      i='a';
    }
    this -> Analisis_[1].insert(&(i));
  }
  this -> Analisis_[1].insert("á");
  this -> Analisis_[1].insert("é");
  this -> Analisis_[1].insert("í");
  this -> Analisis_[1].insert("ó");
  this -> Analisis_[1].insert("ú");
}
Analisis::~Analisis(){ }

void Analisis::Importar(std::string cadena){
  bool operador = false;
  bool especial = false;
  bool signo_puntuacion = false;
  bool numero = false; 
  bool punto = false;
  bool alfabeto = false;
  bool desconocido = false;
  std::for_each(cadena.begin(), cadena.end(), [](char & c){
    c = ::tolower(c);
  });
  if ( cadena.length() == 1) {  //verificamos longitud 1 en caso afirmativo 
                                //buscamos en operadores 1c y signos puntuacion
    if ( this -> Analisis_[5].find(cadena) != this -> Analisis_[5].end() ) {
      operador = true;
    } 
    if ( this -> Analisis_[4].find(cadena) != this -> Analisis_[4].end() ) {
      signo_puntuacion = true;
      if ( cadena == "{") llaves_ +=1; 
      if ( cadena == "}") llaves_ -=1; 
      if ( cadena == "(") parentesis_ +=1; 
      if ( cadena == ")") parentesis_ -=1; 
      if ( cadena == "[") corchetes_ +=1; 
      if ( cadena == "]") corchetes_ -=1; 
    } 
  }
  if ( cadena.length() == 2) {//logitud 2 verificamos los posibles operadores
    if ( this -> Analisis_[3].find(cadena) != this -> Analisis_[3].end() ) {
      operador = true;
    } 
  }
  if( this -> Analisis_[0].find(cadena) != this -> Analisis_[0].end() ){
    especial = true;
  }
  if ( !signo_puntuacion && !operador  && !especial) {
    for ( int i = 0;  i< cadena.length(); i++) {
      std::string simbolo = cadena.substr(i,1);
      if( this -> Analisis_[2].find(simbolo) != this -> Analisis_[2].end() ){
        numero = true;
      } else if ( this -> Analisis_[1].find(simbolo) !=
                  this -> Analisis_[1].end() ) {
        alfabeto = true;
      } else if ( numero && (simbolo) == "." ){
        punto = true;
      } else {
        desconocido = true;
        break;
      }
    } 
  }
  //Insertar en el vector de pares Resultado_
  std::pair< std::string , std::string > aux;
  if ( especial) {
    std::for_each(cadena.begin(), cadena.end(), [](char & c){
      c = ::toupper(c);
    });
    aux.first =cadena;
    aux.second= "";
  } else if (desconocido) {
    aux.first = "DESCONOCIDA";
    aux.second = cadena; 
  } else if (operador) {
    aux.first= "OP";
    aux.second=cadena;
  } else if (signo_puntuacion) {
    aux.first= "SIG";
    aux.second= cadena;
  } else if ( !alfabeto  && !punto  && numero) {
    aux.first="INT";
    aux.second= cadena;
  } else if ( !alfabeto && punto && numero) {
    aux.first="FLOT";
    aux.second=cadena;
  } else {
    aux.first="PAL";
    aux.second= cadena;
  }
  Resultado_.push_back(aux);
}

std::ostream& operator<<(std::ostream &os, Analisis &obj) {
  return obj.write(os);
}
std::ostream& Analisis::write(std::ostream &os) {
  for ( auto i = this -> Resultado_.begin(); i != this -> Resultado_.end(); i++) {
    os << std::get<0>(*i) << " " << std::get<1>(*i) << std::endl;
  }
}

int& Analisis::get_parentesis_(){
  return this->parentesis_;
}

int& Analisis::get_corchetes_(){
  return this->corchetes_;
}

int& Analisis::get_llaves_(){
  return this->llaves_;
}

