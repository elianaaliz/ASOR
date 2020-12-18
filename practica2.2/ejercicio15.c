#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char **argv){ // PASAMOS EL ARCHIVO POR PARAMETRO

	int f;
	f = open(argv[1],O_CREAT | O_RDWR, 0777);
	
	if(f == -1){
		printf("Error al abrir o crear el fichero\n");
		return -1;
	}

	struct flock cerrojo;
	cerrojo.l_type = F_UNLCK;
	cerrojo.l_whence = SEEK_SET;
	cerrojo.l_start = 0;
	cerrojo.l_len = 0;
	cerrojo.l_pid = getpid();

	int status = fcntl(f, F_GETLK, &cerrojo);
	
	if(cerrojo.l_type == F_UNLCK){
		printf("Cerrojo desbloqueado\n");
		cerrojo.l_type = F_WRLCK;

		if(fcntl(f, F_SETLK, &cerrojo) == -1){
			printf("Error al crear el cerrojo");
			close(f);
			return 1;
		} else {
			printf("Creado el cerrojo correctamente\n");
			if(dup2(f, 1) != -1){
				
				// escribimos la hora
				time_t t = time(NULL);
				struct tm *tm = localtime(&t);

				printf("%i:%i:%i\n",tm->tm_hour, tm->tm_min, tm->tm_sec);
				
				sleep(30); // Duerme 30 segundos

				cerrojo.l_type = F_UNLCK;

				if(fcntl(f, F_SETLK, &cerrojo) == -1){
					printf("Error al crear el cerrojo");
					close(f);
					return 1;
				}
			}
			
		}	
	} else{
		printf("Cerrojo bloqueado\n");
		return 1;
	}


	return 1;
}
