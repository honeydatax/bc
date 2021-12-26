#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int arg,char  *argv[]){
	FILE *f;
	FILE *ff;
	char envi[1080];
	char *c;
	printf ("\ec\n\e[44;36m\nmacro calc\n");
	if (arg>1){
		ff=fopen("/tmp/data.in","w");
		f=fopen(argv[1],"r");
		fprintf (ff,"\nn=0\nn\n");
		if (ff!=NULL && f!=NULL){
			while(feof(f)!=1){
				strcpy(envi,"0");
				fgets(envi,1024,f);
				fprintf(ff,"\nprint %s \nprint \"\\n\"\nn=n+%s\nprint \"+=\"\nprint n\nprint \"\\n\"\n",envi,envi);
			}
			fprintf(ff,"\nquit\n");
			fclose(ff);
			fclose(f);
			system("cat /tmp/data.in | bc ");
		}	
	}
	return 0;
}
