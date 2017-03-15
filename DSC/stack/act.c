/*采用动归方法*/
#include <stdio.h>
#include <stdlib.h>
int D[13][13];

void stack(int m)
{
	int i,j;
	for(i=0;i<=m;i++)
		for(j=0;j<=m;j++)
			D[i][j]=0;
	for(i=0;i<=m;i++)
		D[i][0]=1;
	for (i = 1; i <= m; ++i)
	{
		for(j=1;j<=m;j++)
		{
			if (i>=j)
			{
				D[i][j]=D[i-1][j]+D[i][j-1];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int m;
	scanf("%d",&m);
	stack(m);
	printf("%d\n",D[m][m] );
	return 0;
}