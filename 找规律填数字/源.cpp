#include<stdio.h>
#include"БъЭЗ.h"
int main(void)
{
	double a[10];
	double d, q = 0.0;
	for(int i = 0; i < 5; i++)
	{
		scanf_s("%d", &a[i]);
	}
	if((q = a[4]/a[3]) == a[3]/a[2])
	{
		dengbi(a, q);
		display(a);
		return 0;
	}
	else if((d = a[4] - a[3]) == a[3] - a[2])
	{
		dengcha(a, d);
		display(a);
		return 0;
	}
	else if( (a[1] + a[2] == a[3]) && ( a[2] + a[3] == a[4]))
	{
		feibolie(a);
		display(a);
		return 0;
	}
}
