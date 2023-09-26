#include <sched.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int sid, pid, pid1, ppid, status;
	char command[50];
	if (argc < 2) {
		printf("expected arg");
		return -1;
	}
	pid = getpid();
	ppid = getppid();
	sid = getsid(pid);
	sprintf(command, "ps xjf | grep \"%d\" >> %s", sid, argv[1]);
	printf("parent: sid = %i pid=%i ppid=%i \n", sid, pid, ppid);
	if ((pid1 = fork()) == 0)
		execl("child1.out", "child1.out", NULL);
	if (fork() == 0)
		execl("child2.out", "child2.out", argv[1], NULL);
	if (fork() == 0)
		execl("child3.out", "child3.out", NULL);
	system(command);
	waitpid(pid1, &status, WNOHANG);
	return 0;
}
