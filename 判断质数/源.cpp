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
			if(a%i==0)//����г�1�ͱ������������������
			{
			printf("N0\n");
			return 0;//ֱ�ӽ�������  �������䲻������
			}
		}
	}
	if (a==2)
	printf("YES\n");
	else
		printf("NO\n");
	return 0;
}