#include<stdio.h>
int main()
{

	int i = 0, j=0;
	int M, N, T;
	int arr1[10][10]={0}, arr2[10][10]={0};
	scanf_s("%d %d %d", &M, &N, &T);
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<N; j++)
		{
			scanf_s("%d", &arr1[i][j]);
		}
	}

	for (i = 0; i<M; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (T==1){ 
				arr2[M-i-1][j]=arr1[i][j];
				printf("%d ", arr2[i][j]);}
			else {
				arr2[i][N-j-1]=arr1[i][j];
				printf("%d ",arr2[i][j]);}
		}
		printf("\n");
	}
	return 0;
}