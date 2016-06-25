#include<iostream>
using namespace std;
class CBox
{
public:
	CBox(double lv, double bv = 1.0, double hv = 1.0)
	{
		cout << endl << "Constructor called.";
		m_Length = lv;
		m_Width = bv;
		m_Height = hv;
	}
	CBox()
	{
		cout << endl
				<< "Default constructor called.";
		m_Length = m_Width = m_Height = 1.0;
	}
	double Volume() const
	{
		return m_Length * m_Width * m_Height;
	}
private:
	double m_Length;
	double m_Width;
	double m_Height;
};
int main(void)
{
	CBox boxes[5];
	CBox cigar(8.0, 5.0, 1.0);
	cout << endl
		<< "Volume of boxes[3] = " << boxes[3].Volume()
		<< endl
		<< "Volume of cigar = " << cigar.Volume();
	cout << endl;
	return 0;
}