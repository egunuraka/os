#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int pid[4], ppid, status[4], result[4];
	int option[] = {0, WNOHANG, WUNTRACED, WNOHANG};
	pid[0] = getpid();
	ppid = getppid();
	printf("parent: pid=%i  ppid=%i\n", pid[0],ppid);
	for (int j = 1; j < 4; j++) {
		if((pid[1] = fork()) == 0)
			execl("child1","child1", NULL);
		if((pid[2] = fork()) == 0)
			execl("child2","child2", NULL);
		if((pid[3] = fork()) == 0)
			execl("child3","child3", NULL);
		system("ps xf > file.txt");
		for (int i = 1; i < 4; i++) {
			result[i] = waitpid(pid[i], &status[i], option[j]);
			printf("%d,Child proccess with pid = %d is finished with status %d\n", i, result[i], status[i]);
		}
		for (int i = 1; i < 4; i++) {
			if (WIFEXITED(status[i]) == 0) {
				printf("Process with pid = %d was failed\n", pid[i]);
			} else {
				printf("Process with pid = %d was success\n", pid[i]);
			}
		}
	}
	return 0;
}
