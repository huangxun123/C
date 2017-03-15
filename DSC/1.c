#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1601
#define ITERATIONS 26
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main(int argc, char const *argv[])
{
	int i,j,position;
	int list[MAX_SIZE];
	int sizelist[]={0,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800
		,900,1000,1100,1200,1300,1400,1500,1600};
		clock_t start,stop;
		double duration;
		printf("   n   time\n");
		for(i=0;i<ITERATIONS;i++)
		{
			for(j=0;j<list[i];j++)
				list[j]=sizelist[i]-j;
			start=clock();
			sort(list)
		}
	return 0;
}