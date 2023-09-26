#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void real_time_signal_handler(int signal) {
   printf("Real-time Signal %d\n", signal);
}

int main() {
   // Установка обработчика для сигналов реального времени
   struct sigaction sa;
   sa.sa_handler = real_time_signal_handler;
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_RESTART;


   // Генерация сигналов реального времени с номерами меньше 32
   for (int signal = 0; signal <  32; signal++) {
       if(signal !=9 && signal != 19) {
           sigaction(signal, &sa, NULL);
           kill(getpid(), signal);
           usleep(1000); // Задержка 1 миллисекунда
       }
   }


   return 0;
}
