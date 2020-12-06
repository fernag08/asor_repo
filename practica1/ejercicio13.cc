#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(){

   int tiempoTotal = 0;   
   struct timeval *tv;

   for(int i = 0; i < 1000000; i++){}

   gettimeofday(tv, NULL);
 
   printf("Tiempo: %d\n", tv->tv_sec);

   return 0;
}
