#include <stdlib.h>
#include <stdio.h>

int main() {
	int pid = 0;
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	}
	if (pid == 0) {
		system("ls -li > child");
	} else {
		system("ls -li > parent");
	}
	exit(0);
}
