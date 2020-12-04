#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main(){
	time_t tiempo = time(NULL);
	struct tm *t = localtime(&tiempo);
	printf("Año:%i\n",1900+t->tm_year);
	return 1;
}
