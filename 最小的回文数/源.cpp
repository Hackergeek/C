#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[])
{
	char str[10010];
	int len,i,h;
	while(gets(str))
	{ h=0;
	len=strlen(str);
	for(i=0;i<len;i++)
		if(str[i]!='9') break;
	if(i==len)
	{
		printf("1");
		for(i=1;i<len;i++)
			printf("0");
		printf("1\n");
	}//求出99,999,9999...，直接输出
	else {
		for(i=0;i<=len/2;i++)
		{if(str[i]>str[len-1-i]) h=1;//如果高位大于地位，h=1
		str[len-1-i]=str[i];}//以高位为准，如：1234567，1和7，以1为准把7换成1；
		if(h==1)
		{ str[len]='\0';  puts(str); }//直接输出，不用加1
		else {  i--; 
		if(len%2==0)  i--;
		if(str[i]!='9')
		{ str[i]=str[len-1-i]=str[i]+1;h=1; }//最中间那一位不为9，中间位加1，h=1
		if(h==0)//最中间那一位为9
			while(str[i]=='9')
			{
				str[i]=str[len-i-1]='0';
				i--;
				if(str[i]!='9')
				{str[i]=str[len-1-i]=str[i]+1;break;}
			}
			str[len]='\0';
			puts(str);
		}  
	}
	}
	return 0;
}
