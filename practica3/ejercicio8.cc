#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
   
   pid_t pid = fork();

   if(pid == -1){
      perror("ERROR");  
   }
   else if(pid == 0){
      pid_t sid = setsid();
      chdir("/tmp"); // Fijo el directorio de trabajo del demonio a /tmp

      printf("PID %i\n", getpid());
      printf("PPID %i\n", getppid());
      printf("PGID %i\n", getpgid(getppid()));
      printf("SID %i\n", getsid(getppid()));

      int salidaEstandar = open("/tmp/daemon.out", O_CREAT | O_RDWR, 0777);
      int salidaError = open("/dev/null/", O_CREAT | O_RDWR, 0777);
      int entradaEstandar = open("tmp/daemon.err", O_CREAT | O_RDWR, 0777);

      int salidaEstandar2 = dup2(salidaEstandar, 1);
      int salidaError2 = dup2(salidaError, 2);
      int entradaEstandar2 = dup2(entradaEstandar, 0);
      
      if(execvp(argv[1], &argv[1])){
         perror("ERROR");
      }
      
   }
   else{

      printf("PID %i\n", getpid());
      printf("PPID %i\n", getppid());
      printf("PGID %i\n", getpgid(getppid()));
      printf("SID %i\n", getsid(getppid()));
   }
}
