#include<stdio.h>
int main(){
	int m,n,t;
	int arr[100][100];
	int i,j;
	scanf_s("%d%d%d",&m,&n,&t); //��&ȡ��ַ��������m,n,t,���ܸ���m,nѭ��
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(t==0)
				scanf_s("%d",arr[i][n-j]); //ֱ�����ҷ�ת���棬��&ȡ��ַ
			else
				scanf_s("%d", arr[m-i][j]);//ֱ�����·�ת���棬��&ȡ��ַ
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]); //ѭ�������ÿ�����ݺ�ӿո�
		printf("\n");//ÿ�н����ӻس�
	}
	return 0;
}