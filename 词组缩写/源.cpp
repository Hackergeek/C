#include<iostream>
#include<string>
using namespace std;
int main (void)
{
	int T;
	int where;
	string str;
	cin >> T;
	while (T--)
	{
		cin.getline(str,'\n');
		cout << str;
	}
	return 0;
}