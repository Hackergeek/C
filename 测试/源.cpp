#include<stdio.h>
int main(){
	int m,n,t;
	int arr[100][100];
	int i,j;
	scanf_s("%d%d%d",&m,&n,&t); //用&取地址，先输入m,n,t,才能根据m,n循环
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(t==0)
				scanf_s("%d",arr[i][n-j]); //直接左右翻转保存，用&取地址
			else
				scanf_s("%d", arr[m-i][j]);//直接上下翻转保存，用&取地址
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]); //循环输出，每个数据后加空格
		printf("\n");//每行结束加回车
	}
	return 0;
}