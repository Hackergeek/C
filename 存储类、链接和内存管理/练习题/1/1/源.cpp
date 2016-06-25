#include<stdio.h>
int critic(void);
int main(void)
{
	int units = 0;
	printf("How many pounds to a firkin of butter?\n");
	scanf_s("%d", &units);
	while (units != 56)
	{
		units = critic();
	}
	printf("You must have looked it up!\n");
	return 0;
}
int critic(void)
{
	int units = 0;
	printf("No luck, chummy. Try again.\n");
	scanf_s("%d",&units);
	return units;
}