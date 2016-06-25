#include<iostream>
using namespace std;
class CBox
{
public:
	double m_Length;
	double m_Width;
	double m_Height;
	double Volume (void)
	{
		return m_Length * m_Height * m_Width;
	}
};
	int main(void)
	{
		CBox box1;
		CBox box2;
		double boxVolume(0.0);
		box1.m_Height = 18.0;
		box1.m_Length = 78.0;
		box1.m_Width = 24.0;
		box2.m_Height = box1.m_Height - 10;
		box2.m_Length = box1.m_Length / 2.0;
		box2.m_Width = box1.m_Length * 0.25;
		boxVolume = box1.Volume();
		cout << endl
			<< "Volume of box1 = " << boxVolume;
		cout << endl
				<< "Volume of box2 = " << box2.Volume();
		cout << endl
			<< "A CBox object occupies "
			<< sizeof box1 << "bytes.";
		cout << endl;
		return 0;
	}