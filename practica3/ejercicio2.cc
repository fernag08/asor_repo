
#include <string.h>
#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main(int argc, char **argv){
    
    struct sched_param p;

    int pp = sched_getscheduler(0);

    if(pp == SCHED_FIFO){
        printf("FIFO \n");
    }
    else if(pp == SCHED_RR){
        printf("RR \n");
    }
    else if(pp == SCHED_OTHER){
        printf("OTHER \n");
    }

    sched_getparam(0, &p);
    printf("Priority: %i\n", p.sched_priority);

    int maximo = sched_get_priority_max(pp);
    printf("Max priority: %i\n", maximo);

    int minimo = sched_get_priority_min(pp);
    printf("Min priority: %i\n", minimo);
    
}
