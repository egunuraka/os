#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void sigHandler(int sig) {
    printf("Catched signal %s in Child 1\n", (sig == SIGUSR1) ? "SIGUSR1" : "SIGUSR2");
    printf("Parent = %d child = %d\n", getppid(), getpid());
    signal(sig, SIG_DFL);
}

int main() {
    printf("\nChild 1 started: pid = %i, ppid = %i\n", getpid(), getppid());
    signal(SIGUSR1, sigHandler);

    // Отправляем сигналы родителю
    if (kill(getpid(), SIGUSR1) != 0) {
        printf("Error while sending SIGUSR1\n");
        exit(1);
    }

    printf("Successfully sent SIGUSR1 from Child 1\n");
    return 0;
}
