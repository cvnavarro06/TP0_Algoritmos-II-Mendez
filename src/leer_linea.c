#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "leer_linea.h"

#define ERROR -1
#define EXIT -2

const char *SALIDA = "Salir\n";

/*
 * Las lineas de código comentadas son que en las pruebas de xanubot este lo pedido por el enunciado, lo comentado fue usado para testeo
*/

char *leer_linea()
{
	int size = 1;

	char *linea = NULL;
	linea = malloc((size_t)size * sizeof(char));

	if (linea == NULL) {
		return NULL;
	}

	//Leo el input mandado por consola
	int c = fgetc(stdin);

	if (c == EOF) {
		free(linea);
		return NULL;
	}

	bool mal_reservado = false;

	bool salto_linea = false;

	while (c != EOF && !mal_reservado && !salto_linea) {
		//Debo especificar que c tiene que ser un char
		linea[size - 1] = (char)c;
		size++;

		//Reservo memoría para el proximo loop
		char *aux = { NULL };

		aux = realloc(linea, (size_t)size);

		if (aux == NULL) {
			mal_reservado = true;
		} else {
			linea = aux;
			if (c == '\n') {
				salto_linea = true;
			} else {
				c = fgetc(stdin);
			}
		}
	}

	if (mal_reservado) {
		free(linea);
		return NULL;
	}

	//Reservo un espacio más para incluir el '\0'
	char *aux = NULL;
	aux = realloc(linea, (size_t)size + 1);

	if (aux == NULL) {
		free(linea);
		return NULL;
	}

	linea = aux;

	//Cierro el string
	linea[size - 1] = '\0';

	return linea;
}

int leer_linea_ptr(char **ptr, size_t *tamaño)
{
	//Verifico el puntero
	if (ptr == NULL) {
		return ERROR;
	}

	size_t total_leidos = 1;

	int c = fgetc(stdin);

	bool mal_reservado = false;

	if (c == EOF) {
		return ERROR;
	}

	bool salto_linea = false;

	while (c != EOF && !mal_reservado && !salto_linea) {
		if (total_leidos >= *tamaño) {
			(*tamaño)++;

			char *aux = realloc(*ptr, (size_t)(*tamaño) + 1);

			if (aux == NULL) {
				mal_reservado = true;
			}

			if (!mal_reservado) {
				*ptr = aux;
			}
		}
		if (!mal_reservado) {
			(*ptr)[total_leidos - 1] = (char)c;

			if (c == '\n') {
				(*ptr)[total_leidos - 1] = (char)c;
				salto_linea = true;
				total_leidos++;
				(*tamaño)++;
			} else {
				c = fgetc(stdin);
				total_leidos++;
			}
		}
	}

	if (mal_reservado) {
		return ERROR;
	}

	//Cierro el string
	(*ptr)[total_leidos - 1] = '\0';
	(*tamaño)++;

	if (strcmp(*ptr, SALIDA) == 0) {
		return EXIT;
	}

	//Corrijo el total con un -1
	return (int)total_leidos - 1;
}