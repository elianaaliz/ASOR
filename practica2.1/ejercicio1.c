#include<stdio.h>
#include<errno.h>
#include<string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  char *e;
  if(setuid(0) == -1){
    perror(e);
  }
  return 1;
}


