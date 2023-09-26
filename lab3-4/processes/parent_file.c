#include <stdio.h>
#include <sched.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void wrt(char *buf, int value) {
	sprintf(buf, "%d", value);
}

int main(void) {
	int pid, ppid, status;
	int fdrd, fdwr;
	char str1[10], str2[10];
	struct sched_param shdprm;
	if (mlockall(MCL_CURRENT | MCL_FUTURE) < 0)
   		perror("mlockall error");
	pid = getpid();
	ppid = getppid();
	shdprm.sched_priority = 1;
	if (sched_setscheduler(0, SCHED_FIFO, &shdprm) == -1)
   		perror("SCHED_SETSCHEDULER_1");
	if ((fdrd = open("infile.txt", O_RDONLY)) == -1)
		perror("Opening file");
	if ((fdwr = creat("outfile.txt", 0666)) == -1)
		perror("Creating file");
	wrt(str1,fdrd);
	wrt(str2,fdwr);
	for (int i = 0; i < 2; i++) {
		if (fork() == 0) {
			shdprm.sched_priority = 50;
		if (sched_setscheduler(0, SCHED_RR, &shdprm) == -1)
			perror("SCHED_SETSCHEDULER_1");
			execl("child.out", "child.out", str1, str2, NULL);
		}
	}
	if (close(fdrd) != 0)
		perror("Closing file");
	for (int i = 0; i < 2; i++)
		printf("Процесс с pid = %d завершен\n", wait(&status));
	return 0;
}
