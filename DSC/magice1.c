/*算法1：阶数n = 4 * m（m =1，2，3……）的偶魔方的规律如下：
按数字从小到大，即1，2，3……n2顺序对魔方阵从左到右，从上到下进行填充；
将魔方中间n/2列的元素上、下进行翻转；
将魔方中间n/2行的元素左、右进行翻转。*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 15
 int main(int argc, char const *argv[])
 {
 	int square[MAX][MAX];
 	int i,j,size,count,temp;

 	printf("Enter the size of the square:\n");
	scanf("%d",&size);

	if (size < 1|| size > MAX)
	{
		fprintf(stderr, "Error,size is out of range.\n" );
		exit(1);
	}
	if(size%4)
	{
		fprintf(stderr, "Error,size should be n times of 4 .\n");
		exit(2);
	}
	count=1;
//初始化

	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			square[i][j]=count;
			count++;
		}
	}

	for(i=0;i<size/2;i++)
	{
		for(j=size/4;j<size/4*3;j++)
		{
			temp=square[i][j];
			square[i][j]=square[size-1-i][j];
			square[size-1-i][j]=temp;
		}
	}

	for(j=0;j<size/2;j++)
	{
		for (i = size/4; i < size/4*3; ++i)
		{
			temp=square[i][j];
			square[i][j]=square[i][size-j-1];
			square[i][size-j-1]=temp;
		}
	}

	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			printf("%5d",square[i][j] );
		printf("\n");
	}
 	return 0;
 }