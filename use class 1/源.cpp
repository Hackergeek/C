#include <iostream>
using namespace std;
class CBox
{
public:
	double m_Length;
	double m_WIdth;
	double m_Height;
	CBox(double lv, double bv, double hv)
	{
		cout << endl << "Constructor called.";
		m_Length = lv;
		m_WIdth = bv;
		m_Height = hv;
	}
	double Volume ()
	{
		return m_Length * m_WIdth * m_Height;
	}
};
int main (void)
{
	CBox box1 (78.0, 24.0, 18.0);
	CBox cigarBox (8.0, 5.0, 1.0);
	double boxVolume (0.0);
	boxVolume = box1.Volume();
	cout << endl
			<< "Volume of box1 = " << boxVolume;
	cout << endl
			<< "Volume of cigarBox = " << cigarBox.Volume();
	cout << endl;
	return 0;
}