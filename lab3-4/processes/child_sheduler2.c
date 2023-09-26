#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
	struct sched_param shdprm;
	int pid, pid1, pid2, ppid;
	pid = getpid();
	ppid = getppid();
	printf("child2: pid=%i  ppid=%i\n", pid,ppid);
	printf("child2 - Текущая политика планирования для текущего процесса: ");
	switch (sched_getscheduler(0)) {
	   case SCHED_FIFO:
		   printf ("SCHED_FIFO\n");
		   break;
	   case SCHED_RR:
		   printf ("SCHED_RR\n");
		   break;
	   case SCHED_OTHER:
		   printf ("SCHED_OTHER\n");
		   break;
	   case -1:
		   perror ("SCHED_GETSCHEDULER");
		   break;
	   default:
		   printf ("Неизвестная политика планирования\n");
	}
	if (sched_getparam(0, &shdprm) == 0)
		   printf ("Текущий приоритет текущего процесса: %d\n", shdprm.sched_priority);
	   else
		   perror ("SCHED_GETPARAM");
	   return 0;
}
