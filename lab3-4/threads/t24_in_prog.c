#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sched.h>
#include "unistd.h"
pthread_t  t1, t2;
void* thread1() {
   int i, count = 0;
   int tid, pid;
   tid = syscall(SYS_gettid);
   pid = getpid();
   struct sched_param param;
   sched_getparam(pid, &param);
   struct sched_param new_param;
   printf("Thread_1 with thread id = %d and pid = %d is started\n", tid, pid);
   // здесь размещаем собственно функциональный код нити
   // для примера приведен простой бессмысленный код
   for (i = 0; i < 10000000000000; i++){
       /*if(param.sched_priority != sched_getparam(pid, &new_param)){
           printf("new Thread_1's priority = %d\n", new_param.sched_priority);
           param = new_param;
       }*/
       sched_getparam(pid, &new_param) ;//){
       if (i % 1000000 == 0) {
              printf("new Thread_2's priority = %d\n", new_param.sched_priority);
       }
       param = new_param;
   }
}
//sudo renice -n -10 -p 403362
void* thread2(){
   int i, count = 0;
   int tid, pid;
   tid = syscall(SYS_gettid);
   pid = getpid();
   struct sched_param param;
   sched_getparam(pid, &param);
   struct sched_param new_param;
   printf("Thread_2 with thread id = %d and pid = %d is started\n", tid, pid);
   // здесь размещаем собственно функциональный код нити
   // для примера приведен простой бессмысленный код
   for (i = 0; i < 10000000000000; i++){
       //if(param.sched_priority !=
           sched_getparam(pid, &new_param); //){
           printf("new Thread_2's priority = %d\n", new_param.sched_priority);
           param = new_param;
           sleep(10);
       //}
       //printf("Thread_2: %d\n", i);


   }
}
void main() {
   int policy;
   struct sched_param param;
   pthread_attr_t attr_1, attr_2;
   pthread_attr_init(&attr_1);
   pthread_attr_init(&attr_2);
   pthread_attr_setschedpolicy(&attr_1, SCHED_FIFO);
   pthread_attr_setschedpolicy(&attr_2, SCHED_FIFO);
   //значения приоритетов лучше задавать извне –из командной строки или файла
   param.sched_priority = 40;//Приоритет для 1
   pthread_attr_setschedparam(&attr_1, &param);
   param.sched_priority = 30;//Приоритет для 2
   pthread_attr_setschedparam(&attr_2, &param);
   // Стратегия планирования и связанные с ней атрибуты должны быть взяты из описателя
   // атрибутов, на который указывает аргумент attr
   //pthread_attr_setinheritsched(&attr_1,PTHREAD_EXPLICIT_SCHED);
   //pthread_attr_setinheritsched (&attr_2,PTHREAD_EXPLICIT_SCHED);
   /*Стратегия планирования и связанные с ней атрибуты должны быть унаследованы
    Установка атрибута наследованияот родителя*/
   pthread_attr_setinheritsched(&attr_1,PTHREAD_INHERIT_SCHED);
   pthread_attr_setinheritsched(&attr_2, PTHREAD_INHERIT_SCHED);
   /* Установка статуса освобождения ресурсов*/
   //pthread_attr_setdetachstate(&attr_1,PTHREAD_CREATE_DETACHED);
   pthread_attr_getschedparam(&attr_1, &param);
   pthread_attr_getschedpolicy(&attr_1, &policy);
   printf("Thread_1's priority = %d\n", param.sched_priority);
   pthread_attr_getschedparam(&attr_2, &param);
   pthread_attr_getschedpolicy(&attr_2, &policy);
   printf("Thread_2's priority = %d\n", param.sched_priority);
   switch (policy) {
       case SCHED_FIFO :
           printf ("policy SCHED_FIFO\n");
           break;
       case SCHED_RR :
           printf ("policy SCHED_RR\n");
           break;
       case SCHED_OTHER :
           printf ("policy SCHED_OTHER\n");
           break;
       case -1 :
           perror("policy SCHED_GETSCHEDULER");
           break;
       default :
           printf("policy Неизвестная политика планирования\n");
   }
   pthread_create(&t1, &attr_1, thread1, NULL);
   pthread_create(&t2, &attr_2, thread2, NULL);
   pthread_join(t1, NULL);
   pthread_join(t2, NULL);
   pthread_attr_destroy(&attr_1);
   pthread_attr_destroy(&attr_2);
}

