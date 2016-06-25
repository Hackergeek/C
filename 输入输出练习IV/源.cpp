#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	for(int i = 0; i < n;i++)
	{
		int N, M, sum = 0;
		cin >> N;
		for(int j = 0;j < N;j++)
		{
			cin >> M;
			sum += M;
		}
		cout << sum << endl;
	}
	return 0;
}