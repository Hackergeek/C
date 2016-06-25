#include <stdio.h>
int main()
{
	int a;
	int i=0;
	scanf_s("%d",&a);
	if(a>2)
	{
		for(i=2;i*i<=a;i++)
		{
			if(a%i==0)//如果有除1和本身外的因子则不是质数
			{
			printf("N0\n");
			return 0;//直接结束程序  后面的语句不运行了
			}
		}
	}
	if (a==2)
	printf("YES\n");
	else
		printf("NO\n");
	return 0;
}