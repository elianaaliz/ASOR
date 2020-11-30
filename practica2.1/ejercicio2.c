#include<stdio.h>
#include<errno.h>
#include<string.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
  int errno;
  char *error_description;
  if(setuid(0) == -1){
  printf("Error código: %i\n", errno);
  error_description = strerror(errno);
  printf("Error descripcion: %s\n", error_description);
  }
  return 1;

}

