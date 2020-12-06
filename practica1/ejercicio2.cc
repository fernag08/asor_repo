#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>


int main(){

    int error;

    error = setuid(0);
    
    if(error == -1){
       perror("setuid");
       std::cout << "ERROR: " << errno << " " << strerror(errno) << std::endl;
       return -1;
    }

    return 1;
}
