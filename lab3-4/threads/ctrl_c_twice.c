#include <stdio.h>
#include <signal.h>

void handler() {
	static int i = 0;
	puts("^C -signal received");
	if(i++ == 1)
	signal(SIGINT, SIG_DFL);
}

int main() {
	int pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("Current pid = %d and ppid = %d\n", pid, ppid);
	signal(SIGINT, handler);
	while(1);
	return 0;
}
