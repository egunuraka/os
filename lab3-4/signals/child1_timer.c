#include <signal.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void SIGUSR1_handler(int sig_no) {
	time_t st_t;
	st_t = time(NULL);
	printf("child1 (sleeping) получил сигнал %d в %s\n",sig_no, ctime(&st_t));
	exit(0);
}
int main() {
	signal(SIGUSR1, SIGUSR1_handler);
	printf("child1\n");
	sleep(3);
	return 0;
}
