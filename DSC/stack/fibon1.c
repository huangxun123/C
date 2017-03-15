//没用递归的方法，避免了重复的计算
#include <stdio.h>

long fibon(int i)
{
	int j;
	long fib;
	long a=0;long b=1;
	if(i==0)
		return 0;
	else if(i==1)
		return 1;
	else
	{
		for(j=1;j<i;j++)
		{
			fib=a+b;
			a=b;
			b=fib;
		}
		return fib;
	}
}

void main(int argc, char const *argv[])
{
	int i,m;
	while(scanf("%d",&i))
	{
		m=fibon(i);
		printf("fibon(%d)=%d\n",i,m );
	}
}