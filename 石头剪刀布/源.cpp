#include<iostream>
using namespace std;
int main(void)
{
	int N,p1,p2,n;
	char a, b;
	cin >> N;
	while (N--)
	{
		p1 = 0;
		p2 = 0;
		cin >> n;
		while (n--)
		{
			cin >> a >> b;
			if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P'))
			{
				p1++;
			}
			else if ((b == 'R' && a == 'S') || (b == 'P' && a == 'R') || (b == 'S' && a == 'P'))
			{
				p2++;
			}
			else
			{
				p1++;
				p2++;
			}
		}
		if (p1 > p2)
		{
			cout << "player1" << endl;
		}
		else if (p1 < p2)
		{
			cout << "player2" << endl;
		}
		else
		{
			cout << "TIE" << endl;
		}
	}
	return 0;
}