#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("\nChild 2 started: pid = %i, ppid = %i\n", getpid(), getppid());
    signal(SIGINT,SIG_DFL);

    // Отправляем сигналы родителю
    if (kill(getpid(), SIGINT) != 0) {
        printf("Error while sending SIGUSR1\n");
        exit(1);
    }

    printf("Successfully sent SIGINT from Child 2\n");
    return 0;
}
