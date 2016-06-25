#include <iostream>
#include <string>

const int N = 80;

using namespace std;

int fun(char *str, char *substr)
{//请在这个函数里面修改你的代码
	int i, j, k, num = 0;
	for(i = 0; str[i]; i++)
	{
		for(j = i, k = 0; substr[k] == str[i]; k++,j++)
		{
			if(substr[k+1] == '\0')
			{
				num++;
			}
		}
	}
		return num;
}

int main()
{
	char str[N+1], substr[N+1];
	cin.getline(str, N, '\n');
	cin.getline(substr, N, '\n');
	cout<<fun(str, substr)<<endl;
	return 0;
}
