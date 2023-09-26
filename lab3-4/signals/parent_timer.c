#include <signal.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "time.h"

int main() {
	int pid[2];
	char * child[2] = {"child1.out", "child2.out"};
	for(int i = 0; i < 2; i++) {
		if((pid[i] = fork()) == 0) {
			execl(child[i], child[i], NULL);
		}
	}
	printf("parent\n");
	system("ps");
	for(int i = 0;i < 2; i++) {
		kill(pid[i], SIGUSR1);
	}
	time_t st_t;
	st_t = time(NULL);
	printf("Сигнал отправлен в %s\n", ctime(&st_t));
	sleep(2);
	system("ps");
}
