#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h> 
#include <sys/wait.h> 

// Convertimos a funcion el programa del ejercicio anterior
void ejercicio5(){

	printf("El PID:%i\n", getpid());
	printf("El PPID:%i\n", getppid());
	
	int pgid;
	if(pgid = getpgid(getpid()) == -1){
		printf("error");
	}
	printf("El PGID:%i\n", pgid);

	int sid;
	if(sid = getsid(getpid()) == -1){
		printf("error");
	}
	printf("El SID:%i\n", sid);

	struct rlimit f;
	if(getrlimit(RLIMIT_NOFILE, &f) == -1){
		printf("error");
	}
	printf("LIMIT: %li\n", f.rlim_max);
	
	char buf[100];	// se puede mejorar con memoria dinamica(*)
	if(getcwd(buf, 100) == NULL){
		printf("error");
	}

	printf("Directorio: %s\n", buf);
	
}

//Programa principal
int main(int argc, char *argv[]){
	
    pid_t pid = fork();

    switch(pid){
        case -1:
            perror("fork");
            exit(-1);
			break;
        case 0:
			pid_t mi_sid = setsid(); //Creamos una sesión nueva
			char *cwd= chdir("/tmp"); //Fijamos el directorio a /tmp
            printf("Hijo: \n");
            ejercicio5(pid);
            break;
        default:
            sleep(6);
            printf("Padre: \n");
            ejercicio5(pid);
            break;
    }

    return 1;
	
}
