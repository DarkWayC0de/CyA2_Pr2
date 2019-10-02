//
//Archivo: Analiza.cpp
//Fecha: 26/9/2019
//Autor: Diego Cruz Rodríguez
//Titulo: Prácica 2 de Computabilidad y Algoritmia
//Uso de archivo: Implementacion del main y trabajo con parametros de terminal
//

#include <iostream>
#include <fstream>
#include "funciones.h"
#include "analisis.h"

int main(int argc, char *argv[]) {
  switch(argc){
    case 3:{
      std::string namedoc =argv[2]; 
      std::ofstream writefile (namedoc);
      namedoc =argv[1]; 
      std::ifstream readfile (namedoc);
      if (readfile.is_open()){
        if(writefile.is_open()){
          Analisis A;
          std::string palabra;
          readfile>>palabra;
          while(!readfile.eof()){
            A.Importar(palabra);
            if(A.get_parentesis_() < 0 || A.get_corchetes_() < 0 || A.get_llaves_() < 0){
              std::cout << "Error hay más ";
              if(A.get_parentesis_() < 0) std::cout << "Parentes ";
              if(A.get_corchetes_() < 0) std::cout << "Corchetes  ";
              if(A.get_llaves_() < 0) std::cout << "Llaves  ";
              std::cout << "de cierre que de apertura\n";
              break;
            }
            readfile>>palabra;
          }
          writefile<<A;
	  writefile.close();     
          if(A.get_parentesis_() > 0 || A.get_corchetes_() > 0 || A.get_llaves_() > 0 ){
            std::cout << "Error hay ";
            if(A.get_parentesis_() > 0) std::cout <<A.get_parentesis_()<< " Parentes ";
            if(A.get_corchetes_() > 0) std::cout <<A.get_corchetes_()<< " Corchetes  ";
            if(A.get_llaves_() > 0) std::cout <<A.get_llaves_()<<" Llaves  ";
            std::cout << "sin cierre\n";
          }
        } else{           
          std::cout<<"Error, no se ha podido abrir o crear el archivo "<<
                     argv[2]<<
                     " para adquirir los datos.\n";
          comando_desconocido_ayuda();
        }
	readfile.close();
        } else {
          std::cout<<"Error, no Se ha podido abrir el archivo "<<
                     argv[1]<<
                     " para adquirir los datos.\n";
          comando_desconocido_ayuda();
        }
    }
      break;
    default:
      comando_desconocido_ayuda();
  }
  return 0;
}
