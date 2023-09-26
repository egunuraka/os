#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
char * sig_names [4]= {"SIGUSR1", "SIGUSR2", "SIGINT", "SIGCHLD"};
int sigs[4] = {SIGUSR1, SIGUSR1, SIGINT, SIGCHLD};

static void sigHandler(int sig) {
    printf("Catched signal %d\n", sig);
    printf("Process ID = %d\n", getpid());
    signal(sig, SIG_DFL);
}

void* threadFunction(void* arg) {
    int threadNum = *(int*)arg;
    printf("Thread %d started: Thread ID = %lu, Process ID = %d\n", threadNum, pthread_self(), getpid());

    // Отправляем сигналы самому себе (потоку)
    if (pthread_kill(pthread_self(), sigs[threadNum - 1])) {
        printf("Error while sending signal\n");
        exit(1);
    }

    printf("Successfully sent %s signal to Thread %d\n", sig_names[threadNum - 1], threadNum);

    return NULL;
}

int main() {
    printf("Parent process started: Process ID = %d\n", getpid());

    signal(SIGUSR1, sigHandler);
    signal(SIGUSR2, sigHandler);
    signal(SIGINT,SIG_DFL);
    signal(SIGCHLD,SIG_IGN);
    // Создаем и запускаем 3 потока
    pthread_t threads[4];
    int threadNums[4] = {1, 2, 3, 4};

    for (int i = 0; i < 4; ++i) {
        if (pthread_create(&threads[i], NULL, threadFunction, &threadNums[i]) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    // Ожидаем завершения потоков
    for (int i = 0; i < 4; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
