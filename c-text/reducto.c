#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEM 40
int main(int argc, char const *argv[])
{
	FILE *in,*out;
	int ch;
	char name[LEM];
	int count=0;
	if(argc<2)
	{
		fprintf(stderr, "Usage:%s filename\n",argv[0] );
		exit(1);
	}
	if ((in=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr, "Can't open the file %s\n",argv[1] );
		exit(1);
	}
	// strcpy(name,argv[1]);
	// strcat(name,".red");
	if((out=fopen(argv[2],"w"))==NULL)
	{
		fprintf(stderr, "Can't create output file.\n" );
		exit(3);
	}
	while((ch=getc(in))!=EOF)
		// if(count++ %3==0)
			putc(ch,out);
		if(fclose(in)!=0||fclose(out)!=0)
			fprintf(stderr, "Error in closing fileds\n" );
	return 0;
}