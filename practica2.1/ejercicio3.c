#include<stdio.h>
#include<errno.h>
#include<string.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
  int i;
  // for (i=0;i<255;i++){ //Max como limite de errores
  for (i=0;i<134;i++){
    printf("Error(%i):%s\n", i, strerror(i));
  }
  return 1;
}

