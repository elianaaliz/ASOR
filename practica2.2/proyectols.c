#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv){
    
    if(argc < 2){
		printf("Error de argumentos \n");
		return -1;
    }

    DIR *dir = opendir(argv[1]);
    long int tam = 0;
    if(dir == NULL){
       printf("Error opendir");
       return -1;
    }

    struct stat st;
    // analizamos el path de argv[1]
    if(stat(argv[1], &st) == -1){
        printf("Error stat");
		return -1;
    }

    
    struct dirent *actual;
    actual = readdir(dir);
    while(actual != NULL) {
        char pth[200];	// se puede mejorar con malloc -> no olvidar el free
        strcpy(pth, argv[1]);
        strcat(pth, "/");
        strcat(pth, actual->d_name);
	// analizamos los ficheros dentro del directorio 
        if(lstat(pth, &st) == -1){
            printf("Error con lstat");
			return -1;
        }
        else{
            if(S_ISDIR(st.st_mode)) { 
                printf("%s/\n", actual->d_name); 
            }
            else if(S_ISREG(st.st_mode)) { 
                if(st.st_mode & S_IXUSR){	// y ejecutable
                    printf("%s*\n", actual->d_name); 
                }
                else{
                    printf("%s\n", actual->d_name); 
                }
            }
            else if(S_ISLNK(st.st_mode)) { 
                char buf[200];	// se puede mejorar con malloc -> no olvidar el free
                if(readlink(pth, buf, sizeof(buf)) == -1){
                    printf("Error con readlink");
					return -1;
                }
                printf("%s -> %s\n", actual->d_name, buf); 
            }
		    tam = tam + st.st_size; // sumamos el tamaño de ficheros dentro del directorio
        }
		actual = readdir(dir);
    }

    closedir(dir);	// cerramos el dir
	
    printf("Tamaño: %li Kb\n", tam/1000);
    
    return 1;
}