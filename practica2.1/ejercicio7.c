#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(){
	char* ruta = "/home/hlocal/Documentos/practica2.1";
	printf("Número Máximo de enlaces:%li\n",pathconf(ruta,_PC_LINK_MAX));
	printf("Tamaño Máximo de una ruta:%li\n",pathconf(ruta,_PC_PATH_MAX));
	printf("Tamaño Máximo de un fichero:%li\n",pathconf(ruta,_PC_NAME_MAX));
	return 1;
}

