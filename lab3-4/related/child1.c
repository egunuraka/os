#include <stdio.h>
#include <unistd.h>

void main(){
	int pid,ppid;
	pid=getpid();
	ppid=getppid();
	printf("child1: pid=%i ppid=%i Родительский процесс создает и ждёт\n", pid, ppid);
	sleep(3);
}
