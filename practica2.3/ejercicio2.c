#include <sched.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int sched;

	if(sched = sched_getscheduler(getpid()) == -1){
		printf("Error con el proceso");
	}

	switch(sched){
	case SCHED_OTHER:
		printf("SCHED_OTHER\n");
		break;
	case SCHED_FIFO:
		printf("SCHED_FIFO\n");
		break;
	case SCHED_RR:
		printf("SCHED_RR\n");
		break;
	default:
		printf("Otra polictica\n");
	}
	
	struct sched_param a;
	if(sched_getparam(getpid(), &a) == -1){
		printf("error con sched_getparam");
	}
	printf("Prioridad:%d\n", a.sched_priority);

	int prio;
	if(prio = sched_get_priority_max(sched) == -1){
		printf("Error con max prio\n");
	}
	
	printf("Min prio:%i\n", prio);

	if(prio = sched_get_priority_min(sched) == -1){
		printf("Error con min prio\n");
	}

	printf("Max prio:%i\n", prio);

	return 1;
}