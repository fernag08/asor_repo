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

      printf("PID %i\n", getpid());
      printf("PPID %i\n", getppid());
      printf("PGID %i\n", getpgid(getppid()));
      printf("SID %i\n", getsid(getppid()));
      
      //sleep(10); // Duermo al hijo para que el padre termine antes
   }
   else{
      sleep(10); // Duermo al padre para que el hijo termine antes
      
      printf("PID %i\n", getpid());
      printf("PPID %i\n", getppid());
      printf("PGID %i\n", getpgid(getppid()));
      printf("SID %i\n", getsid(getppid()));
   }
}
