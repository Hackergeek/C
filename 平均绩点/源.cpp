#include<iostream>
using namespace std;
#include<string.h>

int main()
{
	char a[80];
	int i,l,n;
	double s;
	while(gets_s(a))
	{
		l=strlen(a);
		for(n=s=i=0;i<l;i=i+2)
		{
			if(a[i]=='A')
				s+=4;
			else if(a[i]=='B')
				s+=3;
			else if(a[i]=='C')
				s+=2;
			else if(a[i]=='D')
				s+=1;
			else
				n++;
		}
		printf(n?"Unknown\n":"%.2lf\n",s/((l+1)/2));
	}
	return 0;
}