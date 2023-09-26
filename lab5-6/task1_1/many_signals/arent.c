#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("\nFather started: pid = %i, ppid = %i\n", getpid(), getppid());
    signal(SIGINT, SIG_DFL);
    signal(SIGCHLD, SIG_IGN);

    // Запускаем дочерний процесс child1
    if (fork() == 0) {
        execl("./child1", "child1", (char *)NULL);
        perror("Error executing child1");
        exit(1);
    }

    // Запускаем дочерний процесс child2
    if (fork() == 0) {
        execl("./child2", "child2", (char *)NULL);
        perror("Error executing child2");
        exit(1);
    }

    // Запускаем дочерний процесс child3
    if (fork() == 0) {
        execl("./child3", "child3", (char *)NULL);
        perror("Error executing child3");
        exit(1);
    }

    // Ждем завершения всех дочерних процессов
    for (int i = 0; i < 3; ++i) {
        wait(NULL);
    }

    // Ждем сигналов
    for (;;) {
        pause();
    }

    return 0;
}
