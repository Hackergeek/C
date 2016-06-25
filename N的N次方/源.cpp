#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	while(scanf_s("%d",&n)!=EOF)
		printf("%d\n",(int)pow(10,n*log10(n)-(int)(n*log10(n))));
	return 0;
}