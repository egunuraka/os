#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
	struct sched_param shdprm;
	int pid, pid1, pid2, ppid, status;
	pid = getpid();
	ppid = getppid();
	printf("parent: pid=%i  ppid=%i\n", pid,ppid);
	shdprm.sched_priority = 50;
	if (sched_setscheduler(0, SCHED_RR, &shdprm) == -1)
		perror("sched_setscheduler");
	if ((pid1=fork()) == 0) {
		shdprm.sched_priority = 60;
		if (sched_setscheduler (pid1, SCHED_RR, &shdprm) == -1)
			perror ("sched_setscheduler");
		execl("child1", "child1", NULL);
	}
	if ((pid2=fork()) == 0) {
		shdprm.sched_priority = 40;
		if (sched_setscheduler (pid1, SCHED_RR, &shdprm) == -1)
			perror ("sched_setscheduler");
		execl("child2", "child2", NULL);
	}
	printf("Текущая политика планирования для текущего процесса: ");
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
	printf("Процесс с pid = %d завершен\n", wait(&status));
	printf("Процесс с pid = %d завершен\n", wait(&status));
	printf("Процесс с pid = %d завершен\n", wait(&status));
	return 0;
}
