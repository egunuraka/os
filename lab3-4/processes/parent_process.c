#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int pid, ppid, status;
	pid = getpid();
	ppid = getppid();
	printf("parent: pid=%i  ppid=%i\n", pid,ppid);
	if(fork() == 0)
		execl("child.out","child.out", NULL);
	system("ps xf > file");
	wait(&status);
	printf("Child proccess is finished with status %d\n", status);
	return 0;
}
