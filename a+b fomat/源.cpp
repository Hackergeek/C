#include<stdio.h>
int main(void){
	int a,b;
	scanf_s("%d%d",&a,&b);
	if (a+b < 1000)
	{
		printf("%d\n",a+b);
		return 0;
	}
	if (a+b < 1000000){
	printf("%d,%d%d%d\n",(a+b)/1000,(a+b)%1000/100,(a+b)%100/10,(a+b)%10);
	return 0;
	}
	printf("%d,%d%d%d,%d%d%d\n",(a+b)/1000000,(a+b)%1000000/100000,(a+b)%100000/10000,(a+b)%10000/1000,(a+b)%1000/100,(a+b)%100/10,(a+b)%10);
	return 0;
}
