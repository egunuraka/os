#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int pid[4], ppid, status, result;
	pid[0] = getpid();
	ppid = getppid();
	printf("parent: pid=%i  ppid=%i\n", pid[0],ppid);
	if((pid[1] = fork()) == 0)
		execl("child1.out","child1.out", NULL);
	if((pid[2] = fork()) == 0)
		execl("child2.out","child2.out", NULL);
	if((pid[3] = fork()) == 0)
		execl("child3.out","child3.out", NULL);
	system("ps xf > file.txt");
	for (int i = 1; i < 4; i++) {
		result = waitpid(pid[i], &status, WUNTRACED);
		printf("%d,Child proccess with pid = %d is finished with status %d\n", i, result, status);
	}
	return 0;
}
