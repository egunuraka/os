#include <stdlib.h>
#include <stdio.h>

int main() {
	int pid = 0;
	int o,c,p;
	o = 1000;
	c = 1000;
	p = 1000;
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	}
	for (int i = 0; i < 5; i++) {
		if (pid == 0) {
			for (int j = 0; j < 5; j++) {
				printf("pid = %d, ppid = %d: o=%d c=%d\n", getpid(),getppid(),o,p);
				o--;
				p--;
			}
		} else {
			for (int j = 0; j < 5; j++) {
				printf("pid = %d, ppid = %d: o=%d p=%d \n", getpid(),getppid(),o,c);
				o--;
				c--;
			}
		}
	}
	printf("Ending process\n");
	exit(0);
}
