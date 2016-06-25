#include<iostream>
using namespace std;
int main(void)
{
	int M,K;
	while (cin >> M >> K, M != 0 || K != 0)
	{
		cout << M + M/K << endl;
	}
	return 0;
}