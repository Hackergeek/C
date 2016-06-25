#include<iostream>
using namespace std;
class CBox
{
public:
	explicit CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
	m_Length(lv), m_Width(bv), m_Height(hv)
	{
		cout << endl << "Constructor called. ";
	}
	double Volume ()
	{
		return m_Length * m_Width * m_Height;
	}
private:
	double m_Length;
	double m_Width;
	double m_Height;
	friend double BoxSurface(CBox aBox);
};
double BoxSurface(CBox aBox)
{
	return 2.0 * (aBox.m_Height *aBox.m_Length + aBox.m_Height * aBox.m_Width + aBox.m_Width * aBox.m_Length);
}
int main (void)
{
	CBox match(2.2, 1.1, 0.5);
	CBox box2;
	cout << endl
			<< "Volume of match = "
			<< match.Volume();
	cout << endl
			<< "Surface area of match = "
			<< BoxSurface(match);
	cout << endl
			<< "Volume of box2 = "
			<< box2.Volume();
	cout << endl
			<< "Surface area of box2 = "
			<< BoxSurface(box2);
	cout << endl;
	return 0;
}