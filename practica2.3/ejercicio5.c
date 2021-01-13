#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){

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
	
	char buf[100];
	if(getcwd(buf, 100) == NULL){
		printf("error");
	}

	printf("Directorio: %s\n", buf);
	return 1;
	
}