#include<iostream>
#include<string>
using namespace std;
int main (void)
{
	string str;
	while (true)
	{
		int where = 0;
		int where1 = 0;
		int where2 = 0;
		int n = 0;
		int m = 0;
		cin >> str;
		where = str.find('B');
		while (true)
		{
			where1 = str.find(')',where);
			if(where1==-1)
				break;
			where = where1+1;
			m++;
		}
		where = str.find('B');
		while (true)
		{
			where2 = str.find('(',where);
			if(where2 == -1)
				break;
			where = where2 + 1;
			n++;
		}
		cout << m - n << endl;
	}
	return 0;
}