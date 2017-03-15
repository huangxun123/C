//会计算很多重复的值
#include <stdio.h>
int fibon(int i)
{
	if(i==0)
		return 0;
	else if(i==1)
		return 1;
	else return fibon(i-1)+fibon(i-2);
	return 0;
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