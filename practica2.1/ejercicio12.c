#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main(){
	time_t t = time(NULL);
	printf("tiempo desde el Epoch:%li\n",t);
	return 1;
}
