#include<iostream>
#include<iomanip>
using namespace std;
int main(void)
{
	double N;
	double max = 0.0;
	double rate[12];
	cin >> N;
	for (int i = 0; i < 12; i++)
	{
		cin >> rate[i];
		if (rate[i] > max)
		{
			max = rate[i];
		}
	}
	cout << setiosflags(ios::fixed)
			<<setprecision(2) << N*max << endl;
	return 0;
}