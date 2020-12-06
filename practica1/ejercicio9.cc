#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	uid_t real = getuid();
	uid_t efectivo = geteuid();
	
	printf("ID real: %d\n", real);
	printf("ID efectivo: %d\n", efectivo);

 	return 0;
}
