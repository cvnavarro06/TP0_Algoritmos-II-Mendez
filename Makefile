GCC_FLAGS=-Wall -Wconversion -Wtype-limits -pedantic -Werror -g
VALGRIND_FLAGS=--leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2 --show-leak-kinds=all --trace-children=yes -s
#Creo un nombre por predeterminado por si el usuario se olvida de mandarlo por parametro
NOMBRE ?= programa

manual:
	@echo "Comandos a ejecutar para probar el programa:\n"
	@echo "1. compile NOMBRE=(Nombre del programa) -> Compila el programa\n"
	@echo "2. run -> Corre el programa.\n"
	@echo "3. valgrind NOMBRE=(Nombre del programa) -> Corre valgrind con los flags correspondientes\n"
	@echo "\nImportante: Se recomienda compilar el programa como primera acción.\n"
	
compile:
	gcc $(GCC_FLAGS) src/*.c -o $(NOMBRE)
	@echo "\nSe ha creado un archivo .o llamado $(NOMBRE)\n\nSi quieres ejecutarlo escribe 'make run NOMBRE=$(NOMBRE)'"


valgrind:
	valgrind $(VALGRIND_FLAGS) ./$(NOMBRE)


run:
	@echo "Ejecutando programa...\n"
	./$(NOMBRE)
	

