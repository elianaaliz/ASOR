#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	printf("Longitud Máxima de argumentos:%li\n",sysconf(_SC_ARG_MAX));
	printf("Número Máximo de hijos:%li\n",sysconf(_SC_CHILD_MAX));
	printf("Número Máximo de ficheros:%li\n",sysconf(_SC_OPEN_MAX));
	return 1;
}



