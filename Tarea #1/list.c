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
} NodoLibro;

typedef struct {
    NodoLibro* primero;
    NodoLibro* ultimo;
} ListaLibros;

ListaLibros* inicializarLista(){
    ListaLibros* lista = (ListaLibros*)malloc(sizeof(ListaLibros));
    assert(lista != NULL);

    lista->primero = NULL;
    lista->ultimo = NULL;

    return lista;
}

// crea un nodo "Libro"
NodoLibro * crearLibro(const char* Titulo,const char* Genero, const char* Autor, const char* Ubicacion, const char* Estado, long long isbn) {
  NodoLibro* new = (NodoLibro*) malloc(sizeof(NodoLibro));
  assert(new != NULL);

  // asignacion de datos
  strncpy(new->libro.titulo, Titulo, sizeof(new->libro.titulo));
  strncpy(new->libro.autor, Autor, sizeof(new->libro.autor));
  strncpy(new->libro.genero, Genero, sizeof(new->libro.genero));
  strncpy(new->libro.ubicacion, Ubicacion, sizeof(new->libro.ubicacion));
  strncpy(new->libro.estado, Estado, sizeof(new->libro.estado));
  new->libro->ISBN = isbn;

  // asignacion de punteros
  new->next = NULL;
  new->prev = NULL;
  new->reservas = NULL;

  return new;
}

// funcion que crea "Libro" para "Biblioteca" (lee cadenas de caracteres)
/* titulo, autor, genero, ISBN, ubicacion*/
void registrarLibro(const char *titulo, const char *genero, const char *autor, const char *ubicacion, const char *estado, long long ISBN, ListaLibros *lista) {
  // creamos el libro con los datos proporcionados
  NodoLibro* nuevoLibro = crearLibro(titulo, genero, autor, ubicacion, estado, ISBN);

  // agregamos el libro a la lista  
  if (lista->primero == NULL){
    lista->primero = nuevoLibro;
    lista->ultimo = nuevoLibro;
  } else {
    lista->ultimo->next = nuevoLibro;
    nuevoLibro->prev = lista->ultimo;
    lista->ultimo = nuevoLibro;
  }  
}


// funcion que muestra 1 instancia de "Libro" (lee cadenas de caracteres)
/* titulo, autor */
void mostrarDatosLibro(ListaLibros* lista, const char* titulo, const char* autor) {
  // La lista está vacía o es nula
  if (lista == NULL || lista->primero == NULL) {
    printf("Disculpe aun nos encontramos actualizando la pagina \n");
    return;
  }

  NodoLibro* actual = lista->primero;
  while (actual != NULL){
    if (strcmp(actual->libro.titulo,titulo) == 0 && strcmp(actual->libro.autor,autor) == 0) {
        
        // en caso de encontrar libro se muestra por pantalla
        printf("Titulo del Libro: %s\n", actual->libro.titulo));
        printf("Autor del Libro: %s\n", actual->libro.autor));
        printf("Genero del Libro: %s\n", actual->libro.genero));
        printf("Ubicacion del Libro: %s\n", actual->libro.ubicacion));
        printf("Estado del Libro: %s\n", actual->libro.estado));
        printf("Codigo ISBN del Libro: %lld\n", actual->libro.ISBN));

        // en caso de existir reservas se muestran por pantalla
        if (actual->reservas != NULL) {
            int pos = 1;
            Reserva *reservas = actual->reservas;
            while (reservas != NULL) {
                printf("#%d -%s\n",pos,reservas->nombre);
                reservas = reservas->next;
                pos++;
            }
        }

        return;
    }

    // avanzar al siguiente libro de la lista
    actual = actual->next;
  }
  
  // en caso de no encontrar el libro
  printf("Lamentablemente la biblioteca aun no maneja el libro pedido");
} // muestra "Libro" especificado

// muestra todos las instancias de "Libro" en "Biblioteca"
/* nada */
void mostrarLibrosBiblioteca(ListaLibros* lista) { 
  // La lista está vacía o es nula
  if (lista == NULL || lista->primero == NULL) {
    printf("Disculpe, aún nos encontramos actualizando la página.\n");
    return;
  }
  
  // Mostrar libros
  NodoLibro* actual = lista->primero;
  int pos = 1;
  while (actual != NULL) {
    printf("|--------------------#%d--------------------|\n", pos);
    printf("Titulo del Libro: %s\n", actual->libro.titulo);
    printf("Autor del Libro: %s\n", actual->libro.autor);
    
    actual = actual->next;
    pos++;
  }
}


// funcion que añade instancia de "Libro" a cola "Reservas" (si libro no existe "ERROR")
/* titulo, autor, nombre_estudiante */
void reservarLibro(const char* titulo, const char* autor, const char* nombreEstudiante, ListaLibros *lista){
  // La lista está vacía o es nula
  if (lista == NULL || lista->primero == NULL) {
    printf("Disculpe, aún nos encontramos actualizando la página.\n");
    return;
  }

  NodoLibro* actual = lista->primero;
  while (actual != NULL) {
    if (strcmp(actual->libro.titulo,titulo) == 0 && strcmp(actual->libro.autor,autor) == 0) {
        // en caso de encontrar libro pedido, crear una reserva
        Reserva * reserva = (Reserva*)malloc(sizeof(Reserva));
        strncpy(reserva->nombre,nombreEstudiante,sizeof(reserva->nombre));

        // agregar reserva a la cola
        reserva->next = actual->reservas;
        actual->reservas = reserva;

        printf("Reserva realizada con exito!.\n");
        return;
    }
    actual = actual->next;
  }

  // no se encontro el libro  
  printf("Lamentablemente la biblioteca aun no maneja el libro pedido");
} 

// funcion que elimina instancia de "Libro" en cola "Reservas"
/* titulo, autor, nombre_estudiante */
void cancelarReservaLibro(const char* titulo, const char* autor, const char* nombreEstudiante, ListaLibros* lista) {
  // La lista está vacía o es nula
  if (lista == NULL || lista->primero == NULL) {
    printf("Disculpe, aún nos encontramos actualizando la página.\n");
    return;
  }

  NodoLibro* actual = lista->primero;
  while (actual != NULL) {
    if (strcmp(actual->libro.titulo,titulo) == 0 && strcmp(actual->libro.autor,autor) == 0) {
        Reserva* reservaActual = actual->reservas;
        Reserva* reservaAnterior = NULL;

        while (reservaActual != NULL) {
            if (strcmp(reservaActual->nombre,nombreEstudiante) == 0) {
                if (reservaAnterior == NULL) {
                    // La reserva a eliminar es la primera en la lista
                    actual->reservas = reservaActual->next;
                } else {
                    // Actualizar el puntero next de la reserva anterior para omitir la reserva actual
                    reservaAnterior->next = reservaActual->next;
                }

                free(reservaActual);
                printf("Reserva cancelada con exito!.\n");
                return;
            }

            reservaAnterior = reservaActual;
            reservaActual = reservaActual->next;
        }

        // No se encontró la reserva para el estudiante
        printf("No se encontró una reserva para el estudiante en este libro.\n");
        return;

    }
    actual = actual->next;
  }
  // No se encontro el libro
  printf("Lamentablemente la biblioteca no maneja el libro solicitado.\n");
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
void retirarLibro(Listalibros) {
  
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
