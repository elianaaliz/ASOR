#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]){

    if (argc < 2) {
      printf("Error con los argumentos\n");
    }

	char *mi_tuberia = "/tuberia1";

  	mkfifo(mi_tuberia, 0777);

	int fd = open(mi_tuberia, O_WRONLY);

	//write(fd, "hola1", 10);
	write(fd, argv[1], strlen(argv[1]));

	close(fd);

  return 1;
}