#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titulo[];
    char autor[];
    char genero[];
    char ubicacion[];
    char estado[];
    int ISBN;
    Reservas *reserva;
} Libro;

/* esta quizas sea una manera mas optima de guardar los datos
typedef struct{
  char datos[] // arreglo con titulo, genero, autor, etc...
  int ISBN;
  Reservas *reserva;
} Libro;
*/

typedef struct {
    Reserva *head;
    Reserva *tail;
    Reserva *current;
} Reservas;

typedef struct{
    Libro *next;
    Libro *prev;
    Libro *head;
    Libro *tail;
    int cantidad;
} Biblioteca;

// funcion que crea "Libro" para "Biblioteca" (lee cadenas de caracteres)
/* titulo, autor, genero, ISBN, ubicacion*/
void registrarLibro(){
  
} // nada

// funcion que muestra 1 instancia de "Libro" (lee cadenas de caracteres)
/* titulo, autor */
void mostrarDatosLibro(){
  
} // muestra "Libro" especificado

// muestra todos las instancias de "Libro" en "Biblioteca"
/* nada */
void mostrarLibrosBiblioteca(){
  
}

// funcion que añade instancia de "Libro" a cola "Reservas" (si libro no existe "ERROR")
/* titulo, autor, nombre_estudiante */
void reservarLibro(){
  
} 

// funcion que elimina instancia de "Libro" en cola "Reservas"
/* titulo, autor, nombre_estudiante */
void cancelarReservaLibro(){
  
}

// if (libro->estado == disponible) || (//estudiante se encuentra en primero en la cola de prioridades == TRUE)
/*{
      libro puede ser retirado;
      libro->estado == RETIRADO / prestado;
   }
   else 
   {
      printf("datos del estudiante que posee el libro");
   }

*/
/* titulo, autor, nombre_estudiante */
void retirarLibro(){
  
}

// Si hay una instancia de "Libro" en "Reservas" actaliza el estado de "libroX->estado == resevado"
// Si NO hay una instancia de "Libro" en "Reservas" se actualiza el estado de "libroX->estado == disponible"
/* titulo, autor */
void devolverLibro(){
  
}

// muestra todos los "Libros" en "Biblioteca" con el estado de "NO DISPONIBLES" junto a los nombres de los estudiantes
/* nada */
void mostrarLibrosPrestados(){
  
}

// ESTE ESTA HARDCORE
/*
  Se lee un archivo CSV proporcionado por el usuario y la app IMPORTA
  TODOS los libros y sus datos, INCLUYENDO la cola de reservas
*/
/* nombre_archivo.csv */
void importarLibroCSV(){
  
}

// ESTE ESTA HARDCORE
/*
  se lee un archivo CSV proporcionado por el usuario y la app EXPORTA
  TODOS los libros y sus datos 
*/
/* nombre_archivo.csv */
void exportarLibroCSV(){
  
}
