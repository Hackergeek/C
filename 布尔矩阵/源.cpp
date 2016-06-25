#include<stdio.h>
#include<string.h>

int main()
{
	int n,m[100][100],r[100],c[100],i,j,x,y,R,C;
	while(scanf_s("%d",&n)!=EOF,n)
	{
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf_s("%d",&m[i][j]);
				r[i]+=m[i][j];
				c[j]+=m[i][j];
			}
			for(R=C=i=0;i<n;i++)
			{
				if(r[i]%2)
				{
					R++;
					x=i+1;
				}
				if(c[i]%2)
				{
					C++;
					y=i+1;
				}
			}
			if(!R&&!C)
				puts("OK");
			else if(R==1&&C==1)
				printf("Change bit (%d,%d)\n",x,y);
			else
				puts("Corrupt");
	}
	return 0;
}