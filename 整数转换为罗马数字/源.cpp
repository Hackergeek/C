#include<stdio.h>
void show(char ch, int n);
int main(void)
{
	int num,n;
	if((scanf_s("%d",&num) == 1)&&(num>=1 ||num <= 3999))
	{
		n = num / 1000;
		show('M', n);
		num %= 1000;
		if(num != 0)
		{
			n = num / 500;
			show('D', n);
			num %= 500;
			if(num != 0)
			{
				n = num / 100;
				show('C', n);
				num %= 100;
				if(num !=0)
				{
					n = num / 50;
					show('L',n);
					num %= 50;
					if(num != 0)
					{
						n = num / 10;
						show('X', n);
						num %= 10;
						if(num != 0)
						{
							switch(num)
							{
							case 1:printf("I");
								break;
							case 2:printf("II");
								break;
							case 3:printf("III");
								break;
							case 4:printf("IV");
								break;
							case 5:printf("V");
								break;
							case 6:printf("VI");
								break;
							case 7:printf("VII");
								break;
							case 8:printf("VIII");
								break;
							case 9:printf("IX");
								break;
							default:return 0;
								break;
							}
						}

					}
				}
			}
		}
	}
	return 0;
}
inline void show(char ch, int n)
{
	for(int i = 0; i < n; i++)
		printf("%c",ch);
}