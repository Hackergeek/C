#include<iostream>
#include<iomanip>
using namespace std;
int main(void)
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		int principal = 0;
		int Q = 0;
		int e = 0;
		int f = 0;
		int g = 0;
		cin >> principal >> Q >> e >> f >> g;
		cout <<  principal + principal * Q / 365 * e / 100 * g / 100
				<< endl
				<< principal + principal * (Q + 365) / 365 * f / 100
				<< endl;
	}
	return 0;
}