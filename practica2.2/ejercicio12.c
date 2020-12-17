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
	if(fd2 == -1){
		printf("Error con fd2\n");
		return -1;
	}
	
	printf("Esto es una prueba..\n");

	dup2(fd2, fd);

	return 1;
}
