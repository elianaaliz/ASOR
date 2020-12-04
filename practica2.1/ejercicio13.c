#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>

int main(){
	int i;
	struct timeval ini;
	struct timeval fin;

	gettimeofday(&ini, NULL);
	
	for(i = 0; i <1000000; i++){
		// printf("Hello World\n");
	}
		
	gettimeofday(&fin, NULL);
	
	printf("Tiempo calculado: %i\n", fin - ini);
	
	return 1;
}
