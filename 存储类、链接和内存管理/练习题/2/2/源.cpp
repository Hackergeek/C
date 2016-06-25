#include<stdio.h>
void kilometers(void);
void miles(void);
int main(void)
{
	int mode = 0;
	printf("Enter 0 for metric mode, 1 for US mode:");
	while (scanf_s("%d", &mode) == 1 || mode == -1)
	{
		switch (mode)
		{
		case 1:miles();
				break;
		case 0:kilometers();
				break;
		}
		printf("Enter 0 for metric mode, 1 for US mode (-1 to quit):");
	}
	printf("Done.\n");
	return 0;
}
void miles(void)
{
	int mile =0;
	double gallons = 0.0;
	printf("Enter distance traveled in miles:");
	scanf_s("%d", &mile);
	printf("Enter fuel consumed in gallons:");
	scanf_s("%lf", &gallons);
	printf("Fuel consumptions %.2lf miles per gallons.\n", double(mile / gallons));
}
void kilometers(void)
{
	int kilometer = 0;
	double liters = 0.0;
	printf("Enter distance traveled in kilometers:");
	scanf_s("%d", &kilometer);
	printf("Enter fuel consumed in liters:");
	scanf_s("%lf", &liters);
	printf("Fuel consumptions %.2lf liters per 100 km.\n", double(liters / kilometer * 100));
}
