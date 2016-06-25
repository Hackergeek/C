#include<stdio.h>
int main(void){
	const int MAX=26;
	char ch[MAX]={0};
	int index=0;
	do 
	{
		ch[index]='a'+index;
		printf("%c",ch[index]);
		++index;
	} while (index<26);
	printf("\n");
	return 0;
}