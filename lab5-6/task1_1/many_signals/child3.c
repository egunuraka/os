#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("\nChild 3 started: pid = %i, ppid = %i\n", getpid(), getppid());
    signal(SIGCHLD,SIG_IGN);

    // Отправляем сигналы родителю
    if (kill(getpid(), SIGCHLD) != 0) {
        printf("Error while sending SIGCHLD\n");
        exit(1);
    }

    printf("Successfully sent SIGCHLD from Child 3\n");
    return 0;
}
