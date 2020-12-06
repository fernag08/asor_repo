#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
   time_t tiempo = time(NULL);
   printf("Tiempo: %d\n", tiempo);

   return 0;
}
