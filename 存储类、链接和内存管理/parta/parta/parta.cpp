#include<stdio.h>
void report_count();
void accmulate(int k);
int count = 0;
int main(void){
	int value;
	register int i;
	printf("Enter a positive integer (0 to quit): ");
	while (scanf_s("%d", &value) == 1 && value > 0)
	{
		++count;
		for (i = value; i >= 0; i--)
		{
			accmulate(i);
		}
		printf("Enter a positive integer (0 to quit): ");
	}
	report_count();
	return 0;
}
void report_count()
{
	printf("Loop executed %d times\n", count);
}