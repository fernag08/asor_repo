#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

void errores_disponibles();

int main(){

    errores_disponibles();

    return 1;
}

void errores_disponibles(){
    for(int i = 0; i < 255; i++){
         std::cout << i << " - " << strerror(i) << std::endl;
    }
}
