#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	uid_t uid = getuid();
	
	struct passwd * pdw = getpwuid(uid);

	printf("Nombre: %s\n", pdw->pw_name);
	printf("Descripcion del usuario: %s\n", pdw->pw_gecos);
	printf("Directorio home: %s\n", pdw->pw_dir);
	
 	return 0;
}
