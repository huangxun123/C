//存储从stack[0]开始
#define MAX 100;
typedef struct 
{
	int key;//暂时只有一个域
}element;
element stack[MAX];
int top=-1;


void add(int top,element item)
{
	if (top>=MAX)
	{
		stack_full();
		return;
	}
	stack[++top]=item;
}

element delete(int top)
{
	if (top==-1)
		stack_empty();
		return stack[top--];
}