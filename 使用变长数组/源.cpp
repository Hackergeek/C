#include<stdio.h>
void main(void)
{
	int sign=-1;
	double n;
	double sum=1.0;
	for(n=2;n<=100;n++)
	{
		sum=sum+(1/n*sign);
		
	}
	printf("%.8f\n",sum);
}