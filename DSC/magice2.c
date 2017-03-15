/*算法2：阶数n = 4 * m（m =1，2，3……）的偶魔方的规律如下：
按数字从小到大，即1，2，3……n2顺序对魔方阵从左到右，从上到下进行填充；
将魔方阵分成若干个4×4子方阵，将子方阵对角线上的元素取出；
将取出的元素按从大到小的顺序依次填充到n×n方阵的空缺处。*/
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
 	int temparry[size*size/2];//存放对角线数据

//初始化

	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			square[i][j]=count;
			count++;
		}
	}
	count=0;
//将初始化的对角线数据按顺序取出并存入数组
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if ((i%4 == j%4)||((i%4 + j%4)==3))
			{
				temparry[count]=square[i][j];
				count++;
			}
		}
	}
//从大到小放入方阵中
	count=size*size/2 -1;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			if ((i%4 == j%4)||((i%4 + j%4)==3))
			{
				square[i][j]=temparry[count];
				count--;
			}
	}
	// 输出
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			printf("%5d",square[i][j] );
		printf("\n");
	}
 	return 0;
 }