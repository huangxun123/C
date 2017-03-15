/* 
    一个操作数序列，从1，2，一直到n，栈A的深度大于n。现在可以进行两种操作： 
    1.将一个数，从操作数序列的头端移动到栈的头端（对应数据结构栈的push操作） 
    2.将一个数，从栈的头端移动到输出序列的尾端（对应数据结构的pop操作） 
    现在对于任意一个N，输入端的数据一定是1，2，3...N，求出可能出现的输出端数据序列的种数。 
    解题思路： 
    就是利用递归回溯，每一个元素只可能进栈出栈一次，所以当所有元素都进过栈后统计所有情况的次数 
*/  
#include <stdio.h>
int sum;

void dfs(int top,int head,int n)
{
	if (head==n+1)
	{
		sum++;
		return;
	}
	if (top>0)
	{
		dfs(top-1,head,n);
	}
	if (head<n+1)
	{
		dfs(top+1,head+1,n);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	sum=0;
	dfs(0,1,n);
	printf("%d\n",sum );
	return 0;
}