#include <iostream>
using namespace std;
class CBox
{
public:
	double m_Length;
	double m_Width;
	double m_Height;
	CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0)
	{
		m_Length = lv;
		m_Width = bv;
		m_Height = hv;
	}
	double Volume()
	{
		return m_Height * m_Length * m_Width;
	}
};
int main(void)
{
	CBox box2;
	cout << endl
			<< "Volume of box2 = "
			<< box2.Volume();
	cout <<endl;
	return 0;
}