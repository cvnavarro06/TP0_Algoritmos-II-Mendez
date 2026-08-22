#include <stdio.h>
#include "leer_linea.h"
#include "leer_linea.c"

#define EXITO 0

int main(int argc, char *argv[])
{
	printf("Ingresa tu nombre: ");

	char *nombre = leer_linea();

    if (nombre == NULL) {
        printf("Ha ocurrido un error a la hora de solicitar memoria\n\n"
               "Cerrando programa...");
        return ERROR;
    }

    size_t tamanio;

    // leer_linea_ptr(&nombre, &tamanio);
	
    printf("Hola %s\n", nombre);
	
    free(nombre);
	
    return EXITO;
}