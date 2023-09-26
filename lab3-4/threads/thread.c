#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include "time.h"
#include "unistd.h"


pthread_t  t1, tn;
void * thread1() {
	printf("Нить 1 запущена\n");
	time_t timer;
	timer = time(NULL);
	int n = 0;
	for(int i = 0; i <10; i++) {
		sleep(5);
		printf("th1 %d\n", n += 5);
	}
	time_t end = time(NULL);
	printf("Время нити 1 %ld\n", -timer + end);
	system("ps axhf > thread1.txt");
}

void * threadn() {
	printf("Нить n запущена\n");
	time_t timer;
	timer = time(NULL);
	int n = 0;
	for(int i = 0; i <10; i++) {
		sleep(1);
		printf("th2 %d\n", n += 1);
	}
	time_t end = time(NULL);
	printf("Время нити n %ld\n", -timer + end);
	system("ps axhf > threadn.txt");
}

void main() {
	system("ps axhf > file.txt");
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&tn, NULL, threadn, NULL);
	system("ps axhf >> file.txt");
	pthread_join(t1, NULL);
	pthread_join(tn, NULL);
	system("ps axhf >> file.txt");
}
