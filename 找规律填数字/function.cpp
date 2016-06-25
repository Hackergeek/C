#include<stdio.h>
void dengbi(int arr[], int q)
{
	for(int i = 5; i < 10; i++)
	{
		arr[i] = arr[i - 1] * q;
	}
}
void dengcha(int arr[], int d)
{
	for(int i = 5; i < 10; i++)
	{
		arr[i] = arr[i - 1] + d;
	}
}
void feibolie(int arr[])
{
	for(int i = 5; i < 10; i++ )
	{
		arr[i] = arr[i - 1] + arr[i -2];
	}
}
void display(int arr[])
{
	for(int i = 5; i < 10; i++)
	{
		if(i < 9)
			printf("%d ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}
}