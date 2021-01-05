#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    sigset_t conjunto;


    sigemptyset(&conjunto);
    sigaddset(&conjunto, SIGINT);
    sigaddset(&conjunto, SIGTSTP);


    sigprocmask(SIG_BLOCK, &conjunto, NULL);

    
    //char *sg = getenv("SLEEP_SECS"); // Obtenemos la variable de entorno
    //int seg = atoi(sg);

    sleep(10);

    sigset_t conjPendiente;
    sigpending(&conjPendiente);

    if(sigismember(&conjPendiente, SIGINT) == 1){ // Si ha recibido la señal SIGINT
        printf("Señal SIGINT recibida");
    }

    if(sigismember(&conjPendiente, SIGTSTP) == 1){ // Si ha recibido la señal SIGTSTP
        printf("Señal SIGTSTP recibida");
        sigset_t sigtstp;
        sigemptyset(&sigtstp);
        sigaddset(&sigtstp, SIGTSTP);
	if(sigprocmask(SIG_UNBLOCK, &sigtstp, NULL) != -1){
            printf("Señal SIGINT desbloqueda");
        }
    }

    return 0;
}
