
#include<stdio.h>
int main(void){
	int n;
	int count(0);
	if((scanf_s("%d",&n) == 1)&&(n >=0&&n<=1000))
	{
		while (n !=1)
		{
			n = n%2? 3*n+1:n/2;
			count ++;
		}
		printf("%d\n",count);
	}
	return 0;
}


