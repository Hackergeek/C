#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	string str;
	int sum = 0;
	cin >> str;
	for (int i = 0; i < str.length() ; i++)
	{
		switch (str[i])
		{
		case '1': sum += 1;
					break;
		case '2': sum += 2;
					break;
		case '3': sum += 3;
					break;
		case '4': sum += 4;
					break;
		case '5': sum += 5;
					break;
		case '6': sum += 6;
					break;
		case '7': sum += 7;
					break;
		case '8': sum += 8;
					break;
		case '9': sum += 9;
					break;
		default: 
					break;
		}
	}
	return 0;
}