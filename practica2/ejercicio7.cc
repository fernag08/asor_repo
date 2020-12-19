#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
   
   mode_t mask = umask(027);
   
   int fd = open("ficheroEjer7.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);

   return 0;
}
