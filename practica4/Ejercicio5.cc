#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv){
    
    int fd1, fd2;
    char buffer[256];

    fd1 = open("TuberiaConNombre1", O_RDONLY | O_NONBLOCK);
    fd2 = open("TuberiaConNombre2", O_RDONLY | O_NONBLOCK);

    int seleccion = 0;
    int maxfd, numTuberiaActual, fdActual;
    int tamLectura = 256;
    fd_set conjunto;
    FD_ZERO(&conjunto);

    while(seleccion != -1){
       
       FD_SET(fd1, &conjunto);
       FD_SET(fd2, &conjunto);

       if(fd1 > fd2){
          maxfd = fd1;
       }
       else{
          maxfd = fd2;
       }
       
       seleccion = select(maxfd + 1, &conjunto, NULL, NULL, NULL);
       
       if(seleccion > 0){
            
           if(FD_ISSET(fd1, &conjunto)){ // Se comprueba si fd1 está en el conjunto
              numTuberiaActual = 1;
              fdActual = fd1;
	   }
           else if(FD_ISSET(fd2, &conjunto)){ // Se comprueba si fd2 está en el conjunto
              numTuberiaActual = 2;
              fdActual = fd2;
           }


           while(tamLectura == 256){
		tamLectura = read(fdActual, buffer, 256);

		printf("Tuberia %i: %s", numTuberiaActual, buffer);
	   }
          

           if(tamLectura != 256 && numTuberiaActual == 1){
	       close(fd1);
	       fd1 = open("TuberiaConNombre1", O_RDONLY | O_NONBLOCK);
           }
           else if(tamLectura != 256 && numTuberiaActual == 2){
	       close(fd2);
       	       fd2 = open("TuberiaConNombre2", O_RDONLY | O_NONBLOCK);
           }

        }
     }

   close(fd1);
   close(fd2);

   return 0;
}
