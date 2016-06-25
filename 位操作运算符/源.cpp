#include<stdio.h>
int main(void)
{
	int i = 1 << 32;
	int j = 1 << (-1);
	printf("%d\n", i);
	printf("%d\n", j);
	return 0;
}