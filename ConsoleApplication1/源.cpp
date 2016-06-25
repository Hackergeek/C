#include<stdio.h>
int main()
{
	int n;
	int a[50];
	int s=0;
	int i;
	while((scanf_s("%d",&n)!=EOF)&&(n!=0))
	{
		for(i=0;i<n;i=i+1)
		{
			scanf_s("%d",&a[i]);
		}
		for(i=0;i<n;i=i+1)
		{
			s=s+a[i];
		}
		printf("%d\n",s);                
	}
	return 0;
}