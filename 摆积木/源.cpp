#include<iostream>
#include<math.h>
using namespace std;
int main (void)
{
	int n = 1;
	int high[50];
	while (n != 0)
	{
		int sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> high[i];
			sum += high[i];
		}
		if (n == 0)
			break;
		int average = sum/n;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += fabsf(high[i] - average);
		}
		cout << sum/2 << endl << endl;
	}
	return 0;
}