#include <stdlib.h>
#include <stdio.h>

int main() {
	int pid, counter = 0;
	char str[100];
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	}
	if (pid == 0) {
		printf("new pid = %d, ppid = %d \n", getpid(),getppid());
		str[counter++] = 'n';
	} else {
		printf("parent pid = %d, ppid = %d \n", getpid(),getppid());
		str[counter++] = 'p';
	}
	printf("Ending process\n");
	str[counter++] = '\0';
	printf("%s\n", str);
	exit(1);
}
