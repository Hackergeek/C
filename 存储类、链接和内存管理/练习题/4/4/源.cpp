#include<stdio.h>
void times(int n);
int main(void)
{
	int n = 0;
	scanf_s("%d", &n);
	for(int i = 0; i < n; i ++)
			times(n);
	return 0;
}
void times(int n)
{
	static int count = 0;
	if (n < 0)
	{
		printf("The function have used %d times.\n", count);
	}
	else
	{
		++count;
	}
}