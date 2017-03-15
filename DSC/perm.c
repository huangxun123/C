#include <stdio.h>
#include <string.h>

//交换两个字符
void Swap(char *a ,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

//在 str 数组中，[start,end) 中是否有与 str[end] 元素相同的
int IsSwap(char* str,int start,int end)
{
	for(;start<end;start++)
	{
		if(str[start] == str[end])
			return 0;
	}
	return 1;
}

//递归去重全排列，start 为全排列开始的下标， length 为str数组的长度
void AllRange2(char* str,int start,int length)
{
	if(start == length-1)
	{
		printf("%s\n",str);
	}
	else
	{
		for(int i=start;i<=length-1;i++)
		{
			if(IsSwap(str,start,i))
			{
				Swap(&str[start],&str[i]); 
				AllRange2(str,start+1,length);
				Swap(&str[start],&str[i]); 
			}
		}
	}
}

void Permutation(char* str)
{
	if(str == NULL)
		return;

	AllRange2(str,0,strlen(str));
}

void main()
{
	char str[] = "abb";
	Permutation(str);
}