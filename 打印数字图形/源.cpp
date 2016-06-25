#include<stdio.h>
int main(void)
{
	int N;
	while((scanf_s("%d", &N) == 1) && ( N <= 9 && N >= 1))
	{
		for( int i = 1; i <= N; i++)
		{
			for (int j = 0; j < N - i; j ++)
				printf(" ");
			for (int k = 1; k <= i; k++)
			{
				printf("%d", k);
			}
			for (int l = i - 1; l > 0; l--)
			{
				printf("%d", l);
			}
			printf("\n");
		}
		for (int i = 1; i < N; i++)
		{
			int l = i;
			while (l--)
			{
				printf(" ");
			}
			for (int j = 1; j <= N - i; j++)
			{
				printf("%d",  j);
			}
			for (int k = N - i - 1; k > 0; k--)
			{
				printf("%d", k);
			}
			printf("\n");
		}
	}
	return 0;
}