#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(){
  struct utsname buf;

  uname(&buf);

  printf("SYSNAME: %s\n", buf.sysname);
  printf("NODENAME: %s\n", buf.nodename);
  printf("RELEASE: %s\n", buf.release);
  printf("VERSION: %s\n", buf.version);
  printf("MACHINE: %s\n", buf.machine);
  printf("DOMAINNAME: %s\n", buf.domainname);

}
