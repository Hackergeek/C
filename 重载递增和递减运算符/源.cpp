#include<iostream>
using namespace std;
class Length
{
private:
	int len;
public:
	Length& const operator++();
	const Length operator++(int);
	Length& const operator--();
	const Length operator--(int);
	Length(int l = 1):
		len(l)
	{
		cout << endl << "Constructor called";
	}
	void ShowLength()
	{
		cout << endl << len;
	}
	~Length()
	{
		cout << endl << "Destructor called.";
	}
};
inline Length& Length::operator++()
{
	++(this->len);
	return *this;
}
inline const Length Length::operator++(int)
{
	Length length = *this;
	++*this;
	return length;
}
int main(void)
{
	Length a(5);
	Length b(a++);
	b.ShowLength();
	a.ShowLength();
	return 0;
}