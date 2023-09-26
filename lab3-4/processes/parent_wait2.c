#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	char *child[] = {"", "child1.out", "child2.out", "child3.out"};
	int pid[4], ppid, status[4], result[4];
	int option[] = {0, WNOHANG, WUNTRACED, WNOHANG};
	pid[0] = getpid();
	ppid = getppid();
	printf("parent: pid=%i  ppid=%i\n", pid[0],ppid);
	for (int i = 1; i < 4; i++) {
		if ((pid[i] = fork()) == 0)
			execl(child[i], child[i], NULL); 
	}
	system("ps xf >> file && printf \"\\n\" >> file");
	for (int i = 1; i < 4; i++) {
		result[i] = waitpid(pid[i], &status[i], option[i]);
		printf("%d,Child proccess with pid = %d is finished with status %d\n", i, result[i], status[i]);
	}
	for (int i = 1; i < 4; i++) {
		if (WIFEXITED(status[i]) == 0) {
			printf("Process with pid = %d was failed\n", pid[i]);
		} else {
			printf("Process with pid = %d was success\n", pid[i]);
		}
	}
	return 0;
}
