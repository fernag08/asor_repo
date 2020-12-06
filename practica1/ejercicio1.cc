#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

    int error;

    error = setuid(0);
    
    if(error == -1){
       perror("setuid");
       return -1;
    }

    return 1;
}
