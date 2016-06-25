#include<iostream>
using namespace std;
void main(void)
{
	int T;
	int arr1[3],arr2[3];
	cin >> T;
	while(T--)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr1[j];
		}
		for (int k = 0; k < 3; k++)
		{
			cin >> arr2[k];
		}
		if (arr1[0] > arr2[0])
		{
			cout << "First" << endl;
		}
		else if (arr1[0] < arr2[0])
		{
			cout << "Second" << endl;
		}
		else
		{
			if (arr1[1] > arr2[1])
			{
				cout << "First" << endl;
			}
			else if (arr1[1] < arr2[1])
			{
				cout << "Second" << endl;
			}
			else
			{
				if (arr1[2] > arr2[2])
				{
					cout << "First" << endl;
				}
				else if (arr1[2] < arr2[2])
				{
					cout << "Second" << endl;
				}
				else
				{
					cout << "Same" <<endl;
				}
			}
		}
	}
}