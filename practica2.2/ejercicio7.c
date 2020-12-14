#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(){
	char *path = "/home/cursoredes/Documents/T2/file6.txt";
	mode_t prev = umask(027);
	// printf("prevt:%i\n",prev);
	open(path, O_CREAT | O_RDONLY, 0777);
	mode_t last = umask(prev);
	printf("Last:%i\n",last);
	return 1;
}
