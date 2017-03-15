#include <stdio.h>
#include <string.h>
#define SIZE 80
int main(void)
{
	char flower[SIZE];
	char addon[]="s smell like old shores.";
	puts("What's your favorite flower?");
	gets(flower);
	// the `gets' function is dangerous and should not be used.

	strcat(flower,addon);
	puts(flower);
	puts(addon);
	return 0;
}