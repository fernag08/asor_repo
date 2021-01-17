#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int main(int argc, char **argv){
	
	int p_h[2];	
	
	if(pipe(p_h) == -1){
	    perror("ERROR al crear la tuberia p_h");
	}	
		
	int h_p[2];
	
	if(pipe(h_p) == -1){
            perror("ERROR al crear la tuberia h_p");
	}	

        pid_t pid = fork();

        if(pid == 0){ // Se ejecuta el proceso hijo
	    
	    if(close(p_h[1]) == -1 || close(h_p[0]) == -1){
                perror("ERROR al cerrar");
            }
            
            char mensajeDelPadre[1024];
            char mensajeDelHijo[1];
	    int bytes;
	    mensajeDelHijo[0] = 'l';
	    
            int i = 0;
            while(i < 10){
	        read(p_h[0], mensajeDelPadre, 1024); // Leemos el mensaje del Padre en el proceso Hijo
		
                printf("Mensaje del proceso Padre: %s", mensajeDelPadre);
    		sleep(1);
		 
                if(i == 9){
		     mensajeDelHijo[0] = 'q';
		}
	        
                write(h_p[1], mensajeDelHijo, 1); // Escribimos el mensaje del Hijo en la tuberia
	        i++;
            }

	    close(p_h[0]);
            close(h_p[1]);

        }
	else{ // Se ejecuta el proceso Padre
	    
            if(close(p_h[0]) == -1 || close(h_p[1]) == -1){
                perror("ERROR al cerrar");
            }
	    
            char mensajeDelPadre[1024]; // Se almacena el mensaje que el Padre lee de la entrada estandar
            char mensajeDelHijo[1];
	    int bytes;
            mensajeDelHijo[0] = 'l';
            
            while(mensajeDelHijo[0] != 'q'){ // Mientras que sea != 'q' el Padre no tiene que finalizar
		    bytes = read(0, mensajeDelPadre, CHAR_MAX);
		        
		    write(p_h[1], mensajeDelPadre, bytes);

 		    read(h_p[0], mensajeDelHijo, 1); // Se lee el mensaje del Hijo para comprobar si tiene que parar la ejecución o no, ya que es la variable de control del bucle.
	    }
            
	    close(p_h[1]);
            close(h_p[0]);
	}

	return 0;

}
