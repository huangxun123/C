#include <stdio.h>

//* d= a+b,where a,b and d are polynomials

int main(int argc, char const *argv[])
{
	int n,a=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	a=(4*i-2)*a/(i+1);
	printf("%d\n",a );	
	return 0;
}