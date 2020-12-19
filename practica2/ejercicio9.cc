#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <stdlib.h>

int main(int argc, char** argv){
   
   struct stat st;
   char* mode;
   
   stat("ficheroRandom.txt", &st);
   
   printf("Major: %i\n", major(st.st_dev));
   printf("Minor: %i\n", minor(st.st_dev));
   printf("I-Nodo del fichero: %i\n", st.st_ino);
   printf("Ultimo acceso : %s\n", ctime(&st.st_atime));

   switch(st.st_mode & S_IFMT){
       case S_IFDIR:
         printf("Tipo de fichero: directorio");
         break;
       case S_IFLNK:
         printf("Tipo de fichero: Enlace simbolico");
         break;
       case S_IFREG:
         printf("Tipo de fichero: Fichero ordinario");
         break;
       default:
         printf("Tipo de fichero: Desconocido");
   }

   return 0;
}
