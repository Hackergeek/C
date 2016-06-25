#include<stdio.h>
int main(void)
{
	const int SIZE = 50;
	int numero[SIZE],score[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		scanf_s("%d %d",&numero[i],&score[i]);
	}
	for (int i = 0; i < SIZE; i++)
	{
		if(score[i]>=80)
		printf("%d %d\n",numero[i],score[i]);
	}
	return 0;
}
