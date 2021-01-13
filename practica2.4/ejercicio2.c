#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

//Continuación del ejercicio anterior
int main(int argc, char *argv[]) {

    pid_t pid;

    int p_h[2];
    int h_p[2];

    pipe(p_h);
    pipe(h_p);

    pid = fork();

    char mensajeDepadre[];

    switch (pid) {

    case -1:
      perror("Error");
      //printf("errorrr\n");
      exit(-1);
    case 0:
      // estamos en el hijo
      close(p_h[1]);
      close(h_p[0]);

      for (int i = 0; i < 10; ++i) {
        /* code */
        bytesleidos = read(p_h[0], &mensajeDepadre, 255);
        printf("hijo: %s\n", mensajeDepadre); 
		sleep(1); 
		write(h_p[1], "q", 1);
        if (i == 9) {
			//xxxxx
        }

	  }
     /*dup2(fd[0],0);
			close(fd[1]);
			close(fd[0]);//cerrado padre
			execlp(argv[3],argv[3],argv[4],NULL);
		
		*/
     break;

    default:
    // estamos padre
    close(p_h[0]);
    close(h_p[1]);

    while () {
			//xxxxx
    }

        /*dup2(fd[1],1);
        close(fd[0]);
        close(fd[1]);//cerrado padre
        execlp(argv[1],argv[1],argv[2],NULL);
        */

    break;

    }

      return 1;
	  
}