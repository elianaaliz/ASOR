#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){
	
	int fd;
	fd = open(argv[1],O_CREAT | O_RDWR, 0777);
	
	if(fd == -1){
		printf("Error con fd\n");
		return -1;
	}

	int fd2 = dup2(fd, 1);
	int fd3 = dup2(fd, 2);
	
	printf("Esto es una prueba..\n");

	perror("Mensaje de error");

	dup2(fd2, fd);
	dup2(fd3, fd);

	return 1;
}
