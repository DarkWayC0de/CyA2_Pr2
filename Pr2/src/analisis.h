//
//Archivo: Analisis.h
//Fecha: 26/9/2019
//Autor: Diego Cruz Rodríguez
//Titulo: Prácica 2 de Computabilidad y Algoritmia
//Uso de archivo: Declaracion clase Analisis
//

#ifndef ANALISIS_H
#define ANALISIS_H
#include <set>
#include <vector>

class Analisis { 
 public:
   Analisis();
   ~Analisis();
   void Importar(std::string nombre);
   std::ostream& write(std::ostream &os);
   int& get_parentesis_();
   int& get_corchetes_();
   int& get_llaves_();

 private:
   int parentesis_, llaves_, corchetes_;
   std::set<std::string> Analisis_[6]; //0 Palabra especiales
                                       //1 abc...ABC...
                                       //2 1234567890
                                       //3 operadores 2c
                                       //4 signo_puntuacion
                                       //5 operadores 1c
   std::vector<std::pair<std::string,std::string>> Resultado_;
};
std::ostream& operator<<(std::ostream &os, Analisis &obj);
#endif //ANALISIS_H
