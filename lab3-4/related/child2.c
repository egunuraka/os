#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(int argc, char *argv[]) {
	int pid,ppid;
	pid=getpid();
	ppid=getppid();
	char command[50];
	sprintf(command, "ps xjf | grep son2 >> %s", argv[1]);
	printf("child2:  pid=%i  ppid=%i\nРодительский процесс завершается раньше чем дочерний завершится без ожидания\n",pid,ppid);
	sleep(20);
	ppid=getppid();
	printf("child2 изменился:  pid=%i  ppid=%i\n",pid,ppid);
	system(command);
}
