#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void *mysig(int sig, void (*hnd)(int) )  {
// надежная обработка сигналов
    struct sigaction act,oldact;
    act.sa_handler = hnd;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask,SIGINT);
    act.sa_flags = 0;
    if(sigaction(sig,&act,0) < 0)
        return SIG_ERR;
    return act.sa_handler;
}
void hndUSR1(int sig) {
    if(sig != SIGUSR1) {
        printf("Catched bad signal %d\n",sig);
        return;
    }
    printf("SIGUSR1 catched\n");
    kill(getpid(),SIGINT);
    //sleep(5);
}

void hndINT(int sig) {
    if(sig != SIGINT) {
        printf("Catched bad signal %d\n",sig);
        return;
    }
    printf("SIGINT catched\n");
    sleep(5);
}

int main() {

    mysig(SIGUSR1, hndUSR1);
    mysig(SIGINT, hndINT);
    for (;;) {
        pause();
    }
    return 0;
}