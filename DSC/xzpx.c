#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 101
// #define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void sort(int list[],int);
void swap(int *x,int *y);
#define COMPARE(x,y) (((x)<(y)) ? 1:((x)>(y)) ? -1:0)
int binserage(int list[],int,int );
int main(int argc, char const *argv[])
{
	int list[MAX];
	int n,i,searchnum,m;
	printf("Enter the num to generate:");
	scanf("%d", &n);
	if(n<1||n>MAX)
	{
		fprintf(stderr, "Improver value of n\n" );
		exit(1);
	}
	srand((unsigned int) time(0));
	for(i=0;i<n;i++)
	{
		list[i]=rand()%1000;
		printf("%d\n",list[i] );
	}
	sort(list,n);
	printf("\nOutput:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",list[i] );
		printf("\n");
	}
	printf("Enter the searchnum:\n" );
	scanf("%d",&searchnum);
	m=binserage(list,n,searchnum);
	if(m!=-1)
		printf("searchnum is list[%d]\n",m);
	else printf("NONE!\n");
	return 0;
}
void sort(int list[],int n)
{
	int i,min,j,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(list[min]>list[j])
				min=j;
			// SWAP(list[i],list[min],temp);
			swap(&list[min],&list[i]);
	}
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int binserage(int list[],int n,int searchnum)
{
	int left=0;
	int right=n-1;
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		switch(COMPARE(searchnum,list[middle]))
		{
			case 1:right=middle-1;
				break;
			case 0:
				return middle;
			case -1:left=middle+1;
				break;

		}
	}
	return -1;
}