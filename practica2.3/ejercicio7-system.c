#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){

	if (argc < 2) {
		printf("Error con los argumentos\n");
    }

	// se puede mejorar con memoria dinamica
	char command[1000] = "./";
	strcat(command, argv[1]);

	if(system(command)){
		printf("Error al ejecutar el comando");
		exit(-1);
	}

	printf("El comando termino de ejecutarse\n");
	
	return 1;
}