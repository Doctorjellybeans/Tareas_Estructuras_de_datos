#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define una estructura para almacenar información sobre un libro
typedef struct {
    char titulo[100];
    char autor[100];
    char genero[50];
    char ubicacion[50];
    char estado[20];
    long long ISBN;  // Usamos long long para almacenar ISBN debido a su longitud
} Libro;

// Define una estructura para representar una reserva de libro
typedef struct {
    char nombre[100];
    Reserva* next;
} Reserva;

// Define una estructura para representar un nodo de libro que incluye su reserva
typedef struct {
    Libro libro;
    Reserva* reservas;  // Puntero a la primera reserva
    NodoLibro* next;
    NodoLibro* prev;
} ListaLibros;

// crea un nodo "Libro"
Libro * crearLibro(char Titulo, char Genero, char Autor, char Ubicacion, char Estado, int isbn) {
  Libro* new = (Libro*) malloc(sizeof(Libro));
  assert(new != NULL);

  // asignacion de datos
  new->titulo = Titulo;
  new->autor = Autor;
  new->genero = Genero;
  new->ubicacion = Ubicacion;
  new->estado = Estado;
  new->ISBN = isbn;

  // asignacion de punteros
  new->next = NULL;
  new->prev = NULL;

  return new;
}

// funcion que crea "Libro" para "Biblioteca" (lee cadenas de caracteres)
/* titulo, autor, genero, ISBN, ubicacion*/
void registrarLibro(char titulo, char genero, char autor, char ubicacion, char estado, int ISBN, Biblioteca *lista)
{
  Libro *libro = crear(Titulo, genero, autor)
} 

// funcion que muestra 1 instancia de "Libro" (lee cadenas de caracteres)
/* titulo, autor */
void mostrarDatosLibro(Biblioteca* lista)
{
  
} // muestra "Libro" especificado

// muestra todos las instancias de "Libro" en "Biblioteca"
/* nada */
void mostrarLibrosBiblioteca(Biblioteca* lista)
{ 
  
  
}

// funcion que añade instancia de "Libro" a cola "Reservas" (si libro no existe "ERROR")
/* titulo, autor, nombre_estudiante */
void reservarLibro(char tituloLibro, char autorLibro, char nombreEstudiante, Biblioteca *lista)
{
  
} 

// funcion que elimina instancia de "Libro" en cola "Reservas"
/* titulo, autor, nombre_estudiante */
void cancelarReservaLibro(char Titulo, char Autor, char Nombre, Biblioteca *lista)
{
    
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
