#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){

  if (argc < 2) {
    printf("Error con los argumentos\n");
  }

  int r = execvp(argv[1], argv + 1);
  if (r == -1) {
    printf("ERROR: No se ha ejecutado correctamente\n");
	exit(-1);
  }

  printf("El comando termino de ejecutarse\n");
  return 1;
}