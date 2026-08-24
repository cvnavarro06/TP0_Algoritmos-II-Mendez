#include <stdio.h>
#include <stdbool.h>
#include "leer_linea.h"

#define EXITO 0
#define ERROR -1
#define EXIT -2


int main(int argc, char *argv[])
{
	printf("Ingresa tu nombre: ");

	char *nombre = leer_linea();

    if (nombre == NULL) {
        printf("Ha ocurrido un error a la hora de solicitar memoria\n\n"
               "Cerrando programa...");
        return ERROR;
    }
    printf("\nBienvenido %s, ingresa los nombres de los alumnos al sistema\n\n", nombre);

    printf("Recueda que para salir del programa debes de ingresar 'Salir'\n\n");

    
    size_t tamanio_l = 10;
    char *linea = malloc(tamanio_l * sizeof(char));

    printf("Ingresa un nombre: ");

    bool salir = false;
    
    int c;
    
    while (!salir && (c = leer_linea_ptr(&linea, &tamanio_l)) != ERROR) {
        
        if (c == EXIT) {
            salir = true;
            printf("Saliendo del programa...\n");
        } else {
        
            printf("%s ha sido ingresado al sistema.\n", linea);

            printf("El largo del nombre %s es de: %d\n\n", linea, c); 
        
            printf("Ingresa otro nombre: ");
        }

    }

    free(linea);
	
    free(nombre);
	
    return EXITO;
}