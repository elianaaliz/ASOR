#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <locale.h>



int main(){
	// export LC_ALL="es_ES";
	// printf("%s\n",setlocale(LC_ALL, "es_ES"));
	time_t tiempo = time(NULL);
	struct tm *t = localtime(&tiempo);
	// printf("Año:%i\n",1900+t->tm_year);
	char buf[300];
	strftime(buf, 300, "%A,%d de %B de %Y,%H:%M",t);
	printf("Hoy:%s\n", buf);
	
	return 1;
}
