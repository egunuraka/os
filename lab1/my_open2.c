#include <stdio.h>


int main (int argc, char* argv[]) {
    char input_string[100];
    input_string[0] = '\0';
    scanf("%s", input_string);

    if (input_string[1] != '\n') {
        if (fopen(input_string,"r") == NULL) {
            printf("%s: неудача при попытке открыть файл %s",argv[0],input_string);
        }
        else {
            printf("%s: файл %s открыт",argv[0],input_string);
        }
    } else {
        printf("открываемый файл не указан");
    }

    return 0;
}
