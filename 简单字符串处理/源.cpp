#include<iostream>
#include<string>
using namespace std;
int main (void)
{
	int N;
	int len;
	string str1,str2;
	cin >> N;
	while (N--)
	{
		cin >> str1 >> str2;
		len = str1.length();
		cout << str1.insert(len/2, str2) << endl;
	}
	return 0;
}