#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <string.h>

int main(int argc, char *argv[]){
           struct stat sb;

           if (argc != 2) {
               fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
               exit(EXIT_FAILURE);
           }

           if (stat(argv[1], &sb) == -1) {
               perror("Error stat");
               exit(EXIT_FAILURE);
           }
	   
	char* hard = malloc(sizeof(char)*(strlen(argv[1])));
	char* sym = malloc(sizeof(char)*(strlen(argv[1])));
	
	strcpy(hard, argv[1]);
	strcpy(sym, argv[1]);

	hard = strcat(hard, ".hard");
	sym = strcat(sym, ".sym");

	if(S_ISREG(sb.st_mode)){
	
	   if(link(argv[1],hard) == -1){
	    printf("No se ha podido crear el enlace duro\n");
	   } else {
	    printf("Se ha podido crear el enlace duro\n");   
	   }

	   if(symlink(argv[1],sym) == -1){
	    printf("No se ha podido crear el enlace simbolico\n");
	   } else {
	    printf("Se ha podido crear el enlace simbolico\n");   
	   }
	
	} else {
		printf("no es un archivo ordinario\n");
	}

	

  return 1;
}


