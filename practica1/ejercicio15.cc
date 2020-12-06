#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
   
   char outstr[200];
   time_t tiempo = time(NULL);   
   struct tm *tmp;
   tmp = localtime(&tiempo);

   strftime(outstr, sizeof(outstr), "%a, %d de %B de %G, %H:%M %n", tmp);

   printf(outstr);

   return 0;
}
