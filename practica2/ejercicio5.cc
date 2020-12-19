#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

   int fd = open("ficheroEjer5.txt", O_RDWR | O_CREAT | O_TRUNC, 00646);

   return 0;
}
