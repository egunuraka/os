#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    char * file = "ls";
    char * path = "/bin/ls";
    char * args[] = {"ls", "-l", NULL };
    char * env[] = { (char*)NULL };
    int pid = fork();
    if (pid == 0) {
        switch (argv[1][0]) {
            case '1':
                execl("/nix/store/j4fwy5gi1rdlrlbk2c0vnbs7fmlm60a7-coreutils-9.1/bin/ls", "/nix/store/j4fwy5gi1rdlrlbk2c0vnbs7fmlm60a7-coreutils-9.1/bin/ls", "-l", (char *)NULL);
                break;
            case '2':
                execlp("ls", "ls", "-l", (char *)NULL);
                break;
            case '3':
                execle("/nix/store/j4fwy5gi1rdlrlbk2c0vnbs7fmlm60a7-coreutils-9.1/bin/ls", "ls", "-l", (char *)NULL, env);
                break;
            case '4':
                execv("/nix/store/j4fwy5gi1rdlrlbk2c0vnbs7fmlm60a7-coreutils-9.1/bin/ls", args);
                break;
            case '5':
                execvp("ls", args);
                break;
            case '6':
                execvpe("ls", args, (char *)NULL, env);
                break;
            default:
                printf("Not 1-6");
                break;
        }
    }
    exit(0);
}
