#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   printf("Enlaces: %ld\n", pathconf("ejercicio6", _PC_LINK_MAX));
   printf("Nombre: %ld\n", pathconf("ejercicio6", _PC_NAME_MAX));
   printf("Ruta: %ld\n", pathconf("ejercicio6", _PC_PATH_MAX));
}
