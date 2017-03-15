/*阶数n = 4 * m + 2（m =1，2，3……）的魔方（单偶魔方）
算法
设k = 2 * m + 1；单偶魔方是魔方中比较复杂的一个。
将魔方分成A、B、C、D四个k阶方阵，如下图这四个方阵都为奇方阵，利用上面讲到的方法依次将A、D、B、C填充为奇魔方。
交换A、C魔方元素，对魔方的中间行，交换从中间列向右的m列各对应元素；对其他行，交换从左向右m列各对应元素。
交换B、D魔方元素，交换从中间列向左m – 1列各对应元素。*/
#include <stdio.h>
// Author: http://furzoom.com/
// N为魔方阶数
#define N 6
 
int main()
{
    int a[N][N] = { {0} };//存储魔方
    int i,k,temp;
    int col,row;// col 列，row 行
 
    //初始化
    k = N / 2;
    col = (k-1)/2;
    row = 0;
    a[row][col] = 1;
    //生成奇魔方A
    for(i = 2; i <= k*k; i++)
    {
        if((i-1)%k == 0 )//前一个数是3的倍数
        {
            row++;
        }
        else
        {
            // if row = 0, then row = N-1, or row = row - 1
            row--;
            row = (row+k)%k;
 
            // if col = N, then col = 0, or col = col + 1
            col ++;
            col %= k;
        }
        a[row][col] = i;
    }
 
    //根据A生成B、C、D魔方
    for(row = 0;row < k; row++)
    {
        for(col = 0;col < k; col ++)
        {
            a[row+k][col+k] = a[row][col] + k*k;
            a[row][col+k] = a[row][col] + 2*k*k;
            a[row+k][col] = a[row][col] + 3*k*k;
        }
    }
 
    // Swap A and C
    for(row = 0;row < k;row++)
    {
        if(row == k / 2)//中间行，交换从中间列向右的m列，N = 2*(2m+1)
        {
            for(col = k / 2; col < k - 1; col++)
            {
                temp = a[row][col];
                a[row][col] = a[row + k][col];
                a[row + k][col] = temp;
            }
        }
        else//其他行，交换从左向右m列,N = 2*(2m+1)
        {
            for(col = 0;col < k / 2;col++)
            {
                temp = a[row][col];
                a[row][col] = a[row + k][col];
                a[row + k][col] = temp;
            }
        }
    }
 
    // Swap B and D
    for(row = 0; row < k;row++)//交换中间列向左m-1列，N = 2*(2m+1)
    {
        for(i = 0;i < (k - 1)/2 - 1;i++)
        {
            temp = a[row][k+ k/2 - i];
            a[row][k+ k /2 -i] = a[row + k][k+k/2 -i];
            a[row + k][k+k/2 -i] = temp;
        }
    }
 
    //输出魔方阵
    for(row = 0;row < N; row++)
    {
        for(col = 0;col < N; col ++)
        {
            printf("%5d",a[row][col]);
        }
        printf("\n");
    }
 
    return 0;
}