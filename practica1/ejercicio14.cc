#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(){

   time_t tiempo = time(NULL);   
   struct tm *tmp = localtime(&tiempo);

   printf("Anio: %d\n", tmp->tm_year + 1900);

   return 0;
}
