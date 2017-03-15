/*奇魔方（阶数n = 2 * m + 1，m =1，2，3……）规律如下：
数字1位于方阵中的第一行中间一列；
向左上方移动，并按照数字的递增顺序将数字填入方格中。如果移出了方格，则进
入魔方对边的方格中。继续填写方格。如果一个方格已经被填入数字，则向下继续
填写方格。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 15

int main(int argc, char const *argv[])
{
	static int square[MAX][MAX];
	int i,j,row,col;
	int count,size;

	printf("Enter the size of the square:\n");
	scanf("%d",&size);

	if (size<1||size>MAX)
	{
		fprintf(stderr, "Error! size is out of range\n" );
		exit(1);
	}
	if(!(size%2))
	{
		fprintf(stderr, "Error!Size is even\n" );
		exit(2);
	}
	for(i=0;i<size;i++)
		for (j = 0; j < size; j++)
			square[i][j]=0;
		i=0;j=(size-1)/2;
		square[i][j]=1;
		for(count=2;count<=size*size;count++)
		{
			row=(i-1>=0) ?(i-1):(size-1);
			col=(j-1>=0) ?(j-1):(size-1);
			if(square[row][col])
				i=(++i)%size;
			else
			{
				i=row;
				j=col;
			}
			square[i][j]=count;
		}
		printf("Magic Square of size %d : \n\n",size );
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j< size; ++j)
				printf("%5d",square[i][j] );
			printf("\n");
		}
	return 0;
}