#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <pwd.h>


int main(){
	uid_t uid = getuid();
	printf("usuario:%i\nusuario_efectivo:%i", getuid(), geteuid());
	
	// agregando la parte del ejercicio 10
	struct passwd *usu;
	usu = getpwuid(uid);
	printf("Username:%s\nHome:%s\nInfo:%s\n",usu->pw_name, usu->pw_dir, usu->pw_gecos);
	return 1;
}
