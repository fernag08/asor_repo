#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    if(execvp(argv[1], &argv[1]) == -1){
         perror("ERROR");
         return -1;
    }

    printf("El comando terminó de ejecutarse\n");

    return 0;
}
