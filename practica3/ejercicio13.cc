#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int parar = 0;

void action(int cont){
  if(cont == SIGUSR1){
       parar = 1;
  }
}


int main(int argc, char *argv[]){

  sigset_t conjunto;
  struct sigaction sAction;

  sigemptyset(&conjunto);
  sigaddset(&conjunto, SIGUSR1);

  sigprocmask(SIG_UNBLOCK, &conjunto, NULL);

  sigaction(SIGUSR1, NULL, &sAction);
  sAction.sa_handler = action;
  sigaction(SIGUSR1, &sAction, NULL);

  int sg = atoi(argv[1]); // Obtengo los segundos pasados como argumento
  int i = 0;

  while((i < sg) && (parar == 0)){
	i++;
	sleep(1);
  }

  if(parar == 0){
     unlink(argv[0]);
  }

  return 0;
    
}
