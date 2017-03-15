#include <stdio.h>

long long int f(int n)
{
	if (n==1||n==0)
	{
		return 1;
	}
	return n*f(n-1);
}

long long int fsum(int start,int end)
{
	long long int sum=1;
	for (int  i = start; i >= end; i--)
	{
		sum*=i;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int n;
	long long s;
	while(scanf("%d",&n))
	{
		long long s1,s2;
		s1=fsum(n*2,n+2)/f(n-1);
		s2=fsum(n*2,n+1)/f(n);
		s=s2-s1;
		printf("%lld\n",s );
	}
	return 0;
}