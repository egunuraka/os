#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sched.h>
#include "unistd.h"

pthread_t t[8];

void* thread1(int n) {
   int i, count = 0;
   int tid, pid;
   tid = syscall(SYS_gettid);
   pid = getpid();
   struct sched_param param;
   sched_getparam(pid, &param);
   struct sched_param new_param;
   printf("Thread_%d with thread id = %d and pid = %d is started\n",n, tid, pid);
   for (i = 0; i < 100; i++){
       sched_getparam(pid, &new_param);
       printf("new Thread_%d's priority = %d\n",n, new_param.sched_priority);
       param = new_param;
       sleep(15);
   }
}

void main() {
   int policy;
   struct sched_param param[8];
   pthread_attr_t attr[8];
   int pr[8] = {0,0,0,0,0,0,0,0};
   for(int i = 0; i < 8; i++) {
       pthread_attr_init(&attr[i]);
       pthread_attr_setschedpolicy(&attr[i], SCHED_RR);
       param[i].sched_priority = pr[i];
       pthread_attr_setschedparam(&attr[i], &param[i]);
       pthread_attr_setinheritsched(&attr[i],PTHREAD_INHERIT_SCHED);
       pthread_attr_getschedparam(&attr[i], &param[i]);
       pthread_attr_getschedpolicy(&attr[i], &policy);
       printf("Thread_%d's priority = %d\n",i + 1, param[i].sched_priority);
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
   }
   for(int i = 0; i < 1; i++)
       pthread_create(&t[i], &attr[i], thread1, i);
   for(int i = 0; i < 1; i++)
       pthread_join(t[i], NULL);
   for(int i = 0; i < 1; i++)
       pthread_attr_destroy(&attr[i]);


}

