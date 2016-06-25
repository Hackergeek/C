#include<stdio.h>

int main()
{
	int n,m,i,j,c,sum=0;
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf_s("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf_s("%d",&c);
			sum+=c;
		}
		if(i<n-1)
		{
			printf("%d\n",sum);
			printf("\n");
			sum=0;
		}
		else
		{
			printf("%d\n",sum);
			sum=0;
		}
	}
	return 0;
}