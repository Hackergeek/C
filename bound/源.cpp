#include <stdio.h>																			//Beyond the bounds of an array
#define SIZE 4
int main(void)
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	int i;
	printf("value1 = %d, value2 = %d\n",value1, value2);						//Different compiler will create different results.
	for ( i = -1; i <= SIZE; i++)															//
	{																									
		arr[i] = 2 * i + i;
	}
	for ( i = -1; i <= SIZE; i++)
	{
		printf("%2d %d\n",i, arr[i]);
	}
	printf("value1 = %d, value2 = %d\n",value1,value2);
	return 0;
}