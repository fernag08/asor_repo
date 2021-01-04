#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>

int main(){
   
   pid_t pid = fork();

   if(pid == -1){
      perror("ERROR");  
   }
   else if(pid == 0){
      pid_t sid = setsid();
      chdir("/tmp"); // Fijo el directorio de trabajo del demonio a /tmp

      int pidHijo = getpid();
      printf("PID %i\n", pidHijo);
      printf("PPID %i\n", getppid());
      printf("PGID %i\n", getpgid(getppid()));
      printf("SID %i\n", getsid(getppid()));
   }
   else{
      wait(pidHijo);
      
      printf("PID %i\n", getpid());
      printf("PPID %i\n", getppid());
      printf("PGID %i\n", getpgid(getppid()));
      printf("SID %i\n", getsid(getppid()));
   }
}
