# Practica 2 Computabilidad y Algorimia

### Objetivos
Identifique clases y objetos que permitan moderlar adecuadamente el escenario
de trabajo que se plantea.

Las diferentes funcionalidades que se precisen feran encapsuladas en metodos
concretos cuya extensión textual se mantuviera acotada.

Formato propuesto para la escritura de programa en  C++ en esta asignatura.

Se recomienta el uso de conjuntos de la STL. Identificar situaciones que el uso
de conjuntos y la operatoria de los mismos facilite la implementación que se 
realiza.



### Evaluación
El programa ha de seguir el paradigma de orientacion a objetos

El código a de ser modular

El comportamiento del programa debe de ajustarse a lo solicitado en el 
enunciado

El código debe cumplir "Google C++ Style Guide"

Capacidad del programador de introducir cambios.



### Introducción
Un programa que lea un fichero de texto clasificando diferentes elementos que 
indentifica en el texeto de acuerdo a un conjunto de categorías es lo que llama
habitualmente un analizador léxico.
Se propone desarollar un programa que realice un anállisis sencillo de texto.


### Ejercicio práctico

Desarollar un programa cliente Analiza.cpp que analiza un fichero que se pasa
por linea de comandos. Resultado en otro fichero de salida que se pasa por 
linea de comandos.

Clasificará el texto en:
1.-Palabras especiales
2.-Palabras no especiales
3.-Numeros enteros
4.-Numeros en punto flotente
5.- Operadores
6.-Signos de puntuación.

Se entrega un conjunto de palabras especiales.

Cualquier palabra que no pertenezca a las palabras especiales es una palabra 
normal

No hay numeros negativos

Operadores + - * / = < > <= >= !=

Signos de puntuacion ( ) [ ] . { } ; ,


Estructura de salida "{categoria} {texto}"

#Categorias
Palabras especial --> la palabra en mayusculas
Palabras no especiales --> PAL
Número enteros --> INT
Número flotante -->  FLOT
Operandores --> OP
Signos de puntuación --> SIG


Codigo fuente escrito de acuerdo  a la guía de estilo de Google para C++

Si se ejecuta solo "./Analizador " mostrar ayuda con uso correcto

El programa no es sensible a mayusculas ni minusculas

Se consideran como separadores de palabras espacios y saltos de línea

Si no es capaz de clasificarla se imprimira como DESCONOCIDA y se sigue 
identificando el resto de palabras.


Si empieza  por numero y despues caracter DESCONOCIDA
Si contiene algun simbolo es DESCONOCIDA
 
###Modificacion 
Verificar la apertura y cierre corchetes, parentesis y llaves de forma correcta, en caso contrario informar de ello.
Si se detecta mas signos de cierre se cierra inmediatamente la apertura y se mostrara un error, en caso de mas signos de apertura se notificara al finalizar el documento de lectura, con un error







