#include "list.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
  int opcion;

  do {
      printf("Menú: \n");
      printf("Opción 1: Registrar libro \n");
      printf("Opción 2: Mostrar datos de un libro especifico \n");
      printf("Opcion 3: Mostrar datos de toda la biblioteca \n");
      printf("Opción 4: Reservar un libro \n");
      printf("Opcion 5: Cancelar la reserva de un libro\n");
      printf("Opcion 6: Retirar libro \n");
      printf("Opcion 7: Devolver libro \n");
      printf("Opcion 8: Mostrar libros prestados \n");
      printf("Opcion 9: Importar libros desde un archivo CSV \n");
      printf("Opcion 10: Exportar libros desde un archivo CSV \n");
        

      printf("Por favor, elija una opción: ");
      scanf("%d", &opcion);

      switch (opcion) {
          case 1:
              char Titulo,Genero,Autor,Ubicacion,Estado;
              int ISBN;
                
              printf("Has seleccionado la Opción 1.\n");
                
              printf("Titulo: ");
              scanf("%s",&Titulo);
              printf("\n");

              printf("Genero: ");
              scanf("%s",&Genero);
              printf("\n");

              printf("Autor: ");
              scanf("%s",&Autor);
              printf("\n");

              printf("Ubicacion: ");
              scanf("%s",&Ubicacion);
              printf("\n");

              printf("Estado: ");
              scanf("%s",&Estado);
              printf("\n");

              printf("ISBN: ");
              scanf("%d",&ISBN);
              printf("\n");

              if (registrarLibro(&Titulo,&Genero,&Autor,&Ubicacion,&Estado,&ISBN) == NULL){
                printf("ERROR \n");
              } else {
                printf("El libro se ha añadido existosamente \n");
              }
              
              break;
            case 2:
              printf("Has seleccionado la Opción 2.\n");

              printf("Titulo: ");
              scanf("%s",&Titulo);
              printf("\n");

              printf("Autor: ");
              scanf("%s",&Autor);
              printf("\n");

              if (mostrarDatosLibros(&Titulo,&Autor) == NULL){
                printf("ERROR \n");
                break;
              } else {
                printf("El libro seleccionado es: \n");
                break;
              }
                
              break;
            case 3:
              printf("Has seleccionado la Opción 3.\n");

              if (mostrarLibrosBiblioteca() == NULL){
                printf("ERROR \n");
              } else {
                printf("FIN \n")
                // printf("cantidad de libros = %d \n", *(cant));
                break;
              }
          
              break;
          case 4:
              char nombre_estudiante[];
              printf("Has seleccionado la Opción 4.\n");

              printf("Titulo: ");
              scanf("%s",&Titulo);
              printf("\n");

              printf("Autor: ");
              scanf("%s",&Autor);
              printf("\n");

              printf("Nombre: ");
              scanf("%s",nombre_estudiante);
              printf("\n");

              if (reservarLibro(&Titulo,&Autor,&nombre_estudiante) == NULL){
                printf("ERROR \n");
              } else {
                printf("FIN del proceso");
              }
          case 5:
              printf("Has seleccionado la Opción 5.\n");

              printf("Titulo: ");
              scanf("%s",&Titulo);
              printf("\n");

              printf("Autor: ");
              scanf("%s",&Autor);
              printf("\n");

              printf("Nombre: ");
              scanf("%s",nombre_estudiante);
              printf("\n");

              if (cancelarReservaLibro(&Titulo,&Autor,&nombre_estudiante) == NULL){
                printf("ERROR \n");
              } else {
                printf("FIN del proceso");
              }
            
              break;
          case 6:
              printf("Has seleccionado la Opción 6.\n");

              printf("Titulo: ");
              scanf("%s",&Titulo);
              printf("\n");

              printf("Autor: ");
              scanf("%s",&Autor);
              printf("\n");

              printf("Nombre: ");
              scanf("%s",nombre_estudiante);
              printf("\n");

              if (retirarLibro(&Titulo,&Autor,&nombre_estudiante) == NULL){
                printf("ERROR \n");
              } else {
                printf("FIN del proceso");
              }
            
              break;
          case 7:
              printf("Has seleccionado la Opción 7.\n");

              printf("Titulo: ");
              scanf("%s",&Titulo);
              printf("\n");

              printf("Autor: ");
              scanf("%s",&Autor);
              printf("\n");

              if (devolverLibro(&Titulo,&Autor) == NULL){
                printf("ERROR \n");
                break;
              } else {
                printf("FIN del proceso \n");
                break;
              }
            
              break;
          case 8:
              printf("Has seleccionado la Opción 8.\n");

              if (mostrarLibrosPrestados() == NULL){
                printf("NO se han prestado libros \n");
                break;
              } else {
                printf("FIN del proceso \n");
                break;
              }
            
              break;
          case 9:
              printf("Has seleccionado la Opción 9.\n");

              if (importarLibroCSV(/*archivo.csv*/) == NULL){
                printf("ERROR \n");
                break;
              } else {
                printf("FIN del proceso");
                break;
              }
            
              break;
          case 10:
              printf("Has seleccionado la Opción 10.\n");

            if (exportarLibroCSV(/*archivo.csv*/) == NULL){
                printf("ERROR \n");
                break;
              } else {
                printf("FIN del proceso");
                break;
              }
              break;
        
            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
    } while (opcion != 4);

    return 0;
}
