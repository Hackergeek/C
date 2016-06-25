#include <iostream>
using namespace std;
int main(void)
{
	int C = 0;
	cin >> C;
	while (C--)
	{
		int N = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (j == N)
				{
					cout << i * j;
				}
				else
				{
					cout << i * j << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}