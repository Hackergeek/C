#include<iostream>
using namespace std;
int main(void)
{
	int T;
	long long sum,a[100];
	cin >> T;
	while (T--)
	{
		sum = 0;
		for(int i = 0; i < sizeof(a); i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}