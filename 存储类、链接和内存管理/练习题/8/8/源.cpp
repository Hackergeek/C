#include<stdio.h>
#include<stdlib.h>
#include"function.h"
int * make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
	int * pa;
	int size;
	int value;
	printf("Enter the number of element: ");
	scanf_s("%d", &size);
	while(size > 0)
	{
		printf("Enter the initialization value: ");
		scanf_s("%d", &value);
		pa = make_array(size, value);
		if(pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of the elements (< 1 to quit): ");
		scanf_s("%d", &size);
	}
}