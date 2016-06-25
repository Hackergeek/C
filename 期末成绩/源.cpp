#include<iostream>
using namespace std;
int main(void){
	int T,n,k,score[1000],count;
	cin >> T;
	while (T--)
	{
		count = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++ )
		{
			cin >> score[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (score[i] > score[k])
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}