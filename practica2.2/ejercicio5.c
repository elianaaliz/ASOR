#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(){
	char *path = "/home/cursoredes/Documents/T2/file5.txt";
	open(path, O_CREAT, 0645);
	return 1;
}
