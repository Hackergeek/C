#include<stdio.h>
int main(void){
	for (int i=0,ch='F';i<6;i++){
		for(int j=0;j<=i;j++){
			printf("%c",(ch-j));								//It can also : printf("%c",'F'-j);
		}
		printf("\n");
	}
	return 0;
}