#include<iostream>
using namespace std;
int main(void)
{
	int N;
	int arr[100];
	while (cin >> N, N)
	{
		int time = 5 * N;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		time += arr[0] * 6;
		for (int i = 0; i < N - 1; i++)
		{
			if (arr[i + 1] > arr[i])
			{
				time += (arr[i + 1] - arr[i]) * 6;
			}
			else
			{
				time += (arr[i] - arr[i + 1]) * 4;
			}
		}
		cout << time << endl;
	}
	return 0;
}