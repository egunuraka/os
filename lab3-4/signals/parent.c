#include <signal.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pid[3];
	char * child[3] = {"child1.out", "child2.out", "child3.out"};
	for(int i = 0; i < 3; i++) {
		if((pid[i] = fork()) == 0) {
			execl(child[i], child[i], NULL);
		}
	}
	system("echo \"До отправки сигналов\"");
	system("ps -l");
	for(int i = 0;i < 3; i++)
	   kill(pid[i], SIGUSR1);
	system("echo После отправки сигналов");
	system("ps -l");
}
