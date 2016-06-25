#include<iostream>
using namespace std;
int main(void)
{
	short tell[10];
	cout << tell <<endl
			<< &tell << endl
			<< tell + 1 << endl 
			<< &tell + 2 << endl
			<< &tell + 1 << endl;
	return 0;
}