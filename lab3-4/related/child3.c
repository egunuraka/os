#include <stdio.h>
#include <unistd.h>

void main() {
	int pid,ppid;
	pid=getpid();
	ppid=getppid();
	printf("child3: pid=%i ppid=%i\nchild3 terminated–zombie\n",pid,ppid);
	ppid=getppid();
	printf("child3:  pid=%i  ppid=%i\n",pid,ppid);
}
