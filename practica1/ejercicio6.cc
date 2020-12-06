#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   
   printf("Argumentos: %ld\n", sysconf(_SC_ARG_MAX));
   printf("Ficheros: %ld\n", sysconf(_SC_OPEN_MAX));
   printf("Hijos: %ld\n", sysconf(_SC_CHILD_MAX));
}
