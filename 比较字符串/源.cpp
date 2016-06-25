#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
string* sort(string* strings, size_t count)
{
	bool swapped(false);
	while (true)
	{
		for (size_t i = 0; i < count - 1; i++)
		{
			if (strings[i] > strings[i + 1])
			{
				swapped = true;
				strings[i].swap(strings[i + 1]);
			}
		}
		if (!swapped)
		{
			break;
		}
		swapped = false;
	}
	return strings;
}
int main(void)
{
	const size_t maxstrings(100);
	string strings[maxstrings];
	size_t nstrings(0);
	size_t maxwidth(0);
	while (nstrings < maxstrings)
	{
		cout << "Enter a word or press Enter to end: ";
		getline(cin, strings[nstrings]);
		if (maxwidth < strings[nstrings].length())
		{
			maxwidth = strings[nstrings].length();
		}
		if (strings[nstrings].empty())
		{
			break;
		}
		++nstrings;
	}
	sort(strings, nstrings);
	cout << endl
			<< "In ascending sequence, the words you entered are: "
			<< endl
			<< setiosflags(ios::left);
	for (size_t i = 0; i < nstrings; i++)
	{
		if(i % 5 == 0)
			cout << endl;
		cout << setw(maxwidth + 2) << strings[i];
	}
	cout << endl;
	return 0;
}