#include <stdio.h>
#include "unistd.h"

int main() {
	int pid,ppid;
	pid = getpid();
	ppid = getppid();
	printf("child: pid=%i ppid=%i\n", pid, ppid);
	sleep(5);
	return 0;
}
