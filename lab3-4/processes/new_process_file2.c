#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE * file = fopen("file", "w");
	int pid = 0;
	pid = fork();
	if (pid == -1) {
		perror("fork");
		fclose(file);
		exit(1);
	}
	if (pid == 0) {
		fprintf(file, "new pid = %d, ppid = %d \n", getpid(),getppid());
	} else {
		fprintf(file, "parent pid = %d, ppid = %d \n", getpid(),getppid());
	}
	fclose(file);
	printf("Ending process\n");
	exit(0);
}
