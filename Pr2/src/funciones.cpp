//
//Archivo: funciones.h
//Fecha: 26/9/2019
//Autor: Diego Cruz Rodríguez
//Titulo: Prácica 2 de Computabilidad y Algoritmia
//Uso de archivo: Implementacion de funciones basicas del programa
//
#include "funciones.h"
#include <iostream>
void comando_desconocido_ayuda(){
  std::cout<<"Comando desconocido.\n\n"<<
             "---------------------------------------------------------\n"<<
             "Para el correcto funcionamiento del programa se tiene que\n"<<
             "usar el siguiente comando \"./Analiza\" seguido de el archivo\n"<<
             "de entrada de datos y el archivo de salida.\n"<<
             "---------------------------------------------------------\n"<<
             "Ejemplo de uso.\n"<<
             "./Analza doc_datos doc_salida\n"<<
             "---------------------------------------------------------\n";
}
