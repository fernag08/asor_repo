#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
     
     int tub[2];
     char buffer;

     if(argc != 5){ // Primero compruebo que el numero de argumentos introducido sea el correcto.
        printf("ERROR. El numero de argumentos es incorrecto");
        return -1;
     }

     if(pipe(tub) == -1){ // Creamos la tuberia donde tub[0] es un fd de solo lectura y tub[1] es un fd de solo escritura
        perror("ERROR. Tuberia no creada");
        return -1;
     }

     pid_t pid = fork();

     if(pid == 0){ // Se ejecuta el proceso Hijo
        dup2(tub[0], 0);
        close(tub[0]);
        close(tub[1]);
        execlp(argv[3], argv[3], argv[4], NULL);
     }
     else{ // Se ejecuta el proceso Padre
        dup2(tub[1], 1);
        close(tub[0]);
        close(tub[1]);
        execlp(argv[1], argv[1], argv[2], NULL);
     }
     
   return 0;
}
