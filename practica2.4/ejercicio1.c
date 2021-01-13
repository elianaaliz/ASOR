#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(int argc, char *argv[]) {

    if (argv < 2) {
        printf("Error con los argumentos\n");
    }
    pid_t pid;

    int fd[2];

    pipe(fd);

    pid = fork();

    switch (pid) {

    case -1:
        perror("Error");
        // printf("errorrr\n");
        exit(-1);
    case 0:
        // estamos en el hijo

        dup2(fd[0], 0);
        close(fd[1]);
        close(fd[0]); //cerrado padre
        execlp(argv[3], argv[3], argv[4], NULL);
        break;

    default:
        // estamos padre

        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]); //cerrado padre
        execlp(argv[1], argv[1], argv[2], NULL);

        break;

    }

    return 1;
}