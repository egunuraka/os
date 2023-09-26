#include <stdio.h>
#include <sched.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

int main () {
	struct sched_param shdprm;
	struct timespec qp;
	int i, pid, pid1, pid2, pid3, ppid, status;
	pid = getpid();
	ppid = getppid();
	printf("parent: pid=%i ppid=%i\n", pid, ppid);
	shdprm.sched_priority = 50;
	if (sched_setscheduler(0, SCHED_OTHER, &shdprm) == -1)
		perror("SCHED_SETSCHEDULER_1");
	if (sched_rr_get_interval(0, &qp) == 0)
		printf("Квант: %ld сек %ld нс\n", qp.tv_sec, qp.tv_nsec);
	else
		perror("SCHED_RR_GET_INTERVAL");
	if ((pid1 = fork()) == 0) {
		if (sched_rr_get_interval(pid1, &qp) == 0)
   			printf("child: Квант процессорного времени: %ld сек %ld нс\n", qp.tv_sec, qp.tv_nsec);
		execl("child.out", "child.out", NULL);
	}
	printf("Процесс с pid = %d завершен\n", wait(&status));
	return 0;
}
