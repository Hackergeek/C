#include<iostream>
#include<iomanip>
using namespace std;
int main(void)
{
	double sum = 0;
	int sign = 1;
	for (double n = 1; n <= 100; n++)
	{
		sum += 1/n*sign;
		sign *= -1;
	}
	cout << setprecision(8) << sum << endl;
}