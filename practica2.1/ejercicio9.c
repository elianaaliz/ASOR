#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	printf("usuario:%i\nusuario_efectivo:%i", getuid(), geteuid());
	return 1;
}
