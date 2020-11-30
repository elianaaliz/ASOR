#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

int main(){
	struct utsname buf;
	uname(&buf);
	printf("sysname:%s\nnodeman:%s\nrealese:%s\nversion:%s\nmachine:%s\n",buf.sysname,buf.nodename,buf.release,buf.version,buf.machine);
	return 1;
}

