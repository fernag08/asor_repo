#include <string.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/time.h> 
#include <sys/resource.h>  

int main(int argc, char **argv){
      printf("PID: %i\n", getpid());     
      printf("PPID: %i\n", getppid());     
      printf("PGID: %i\n", getpgid(getpid()));
      printf("SID: %i\n", getsid(getpid())); 

      struct rlimit lim;      
      getrlimit(RLIMIT_NOFILE, &lim);

      printf("Numero maximo de ficheros que puede abrir el proceso: %lli\n", lim.rlim_max);            
            
      char buffer[2048];
      getcwd(buffer, 2048);
      printf("Directorio de trabajo actual: %s\n", buffer);
}
