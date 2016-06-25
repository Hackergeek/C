#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(void)
{
	char a[20];
	string str;
	cout << strlen(a)
			<< endl
			<< str.size();
	cout << endl;
	int i=6;
	do {
		printf("%d", i--);
	} while (0);
	return 0;
}