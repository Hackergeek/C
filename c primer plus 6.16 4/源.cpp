#include<stdio.h>
int main(void){
	for (int i=0;i<5;i++){
		for(int j=0;j<5-i;j++)
			printf(" ");
		for(int j=0;j<=i;j++)
			printf("%c",'A'+j);
		for(int j=0;j<i;j++)
			printf("%c",'A'-1-j+i);
		printf("\n");
	}
	return 0;
}
/* It can also:
#include<stdio.h>  
int main(void) {   
	int i,j,k;  char letter;   
	printf("Please input a capital:");  
	scanf("%c",&letter); 
	k=letter-'A'+1;  
	for(i=0;i<k;i++)  {    
		for(j=0;j<k-i;j++) printf(" ");   
		for(j=0;j<=i;j++) printf("%c",'A'+j);  
		for(j=i-1;j>=0;j--) printf("%c",'A'+j);   
		printf("\n");  }  
	return(0); 
} 
*/