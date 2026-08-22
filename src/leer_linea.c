#include <stdio.h>
#include <stdbool.h>
#include "leer_linea.h"

#define ERROR -1
char *leer_linea()
{
	//Inicializo un puntero.
	
	int size = 1;
	
	char *linea = malloc(size * sizeof(char));

	if (linea == NULL) {
		return NULL;
	}

	//Leo el input mandado por consola
	int c = fgetc(stdin);

	bool mal_reservado = false;

	while (c != '\n' && !mal_reservado) {

		//Debo especificar que c tiene que ser un char
		linea[size - 1] =  (char)c;
		
		size++;
		
		//Reservo memoría para el proximo loop
		char *aux = realloc(linea, size);

		if (aux == NULL) {
			mal_reservado = true;
			//Libero lo que ya reserve
			free(linea);
		} else {
			linea = aux;
		}

		c = fgetc(stdin);
	}

	linea[size - 1] = '\0';

	if (mal_reservado) {
		return NULL;
	}

	return linea;
}

int leer_linea_ptr(char **ptr, size_t *tamaño)
{
	return ERROR;
}