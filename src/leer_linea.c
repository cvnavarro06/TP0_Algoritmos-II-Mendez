#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "leer_linea.h"

#define ERROR -1
#define EXIT -2

const char *SALIR = "Salir";


char *leer_linea()
{
	
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
			free(linea);
		} else {
			linea = aux;
		}

		c = fgetc(stdin);
	}

	//Cierro el string
	linea[size - 1] = '\0';

	if (mal_reservado) {
		return NULL;
	}

	return linea;
}

int leer_linea_ptr(char **ptr, size_t *tamaño)
{

	//Verifico el puntero y el tamaño
	if (ptr == NULL || tamaño == 0) {
		return ERROR;
	}

	size_t total_leidos = 1;

	int c = fgetc( stdin);

	bool mal_reservado = false;

	while (c != '\n' && !mal_reservado) {

		if (total_leidos >= *tamaño) {
			char *aux = realloc (*ptr, (*tamaño) + 1);
			if (aux == NULL) {
				mal_reservado = true;
			}

			if (!mal_reservado) {
				*ptr = aux;
			}

			(*tamaño)++;
		}

		(*ptr)[total_leidos - 1] = (char)c;

		c = fgetc(stdin);

		total_leidos++;
	}

	if (strcmp(*ptr, SALIR) == 0) {
		return EXIT;
	}

	if (mal_reservado) {
		free(ptr);
		return ERROR;
	}

	//Cierro el string
	(*ptr)[total_leidos - 1] = '\0';

	return total_leidos;
}