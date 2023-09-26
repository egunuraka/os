#include <stdlib.h>
#include <stdio.h>

int main() {
	int pid = 0;
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	}
	FILE * file = fopen("file", "w");
	if (pid == 0) {
		fprintf(file, "new pid = %d, ppid = %d \n", getpid(),getppid());
	} else {
		fprintf(file, "parent pid = %d, ppid = %d \n", getpid(),getppid());
	}
	fclose(file);
	printf("Ending process\n");
	exit(0);
}
