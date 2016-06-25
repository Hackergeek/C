#include<iostream>
#include<utility>
using namespace std;
class CBox
{
public:
	explicit CBox (double lv = 1.0, double wv = 1.0, double hv = 1.0) : m_Height(hv)
	{
		m_Length = max(lv, wv);
		m_Width = min(lv, wv);
		if (m_Height > m_Length)
		{
			m_Height = m_Length;
			m_Length = hv;
			double temp = m_Width;
			m_Width = m_Height;
			m_Height = temp;
		}
		else if(m_Height > m_Width)
		{
			m_Height = m_Width;
			m_Width = hv;
		}
	}
	double Volume () const
	{
		return m_Length * m_Width * m_Height;
	}
	bool operator < (const CBox& aBox) const
	{
		return this->Volume() < aBox.Volume();
	}
	bool operator < (const double& value) const
	{
		return this->Volume() < value;
	}
	bool operator > (const double& value) const
	{
		return this->Volume() > value;
	}
	bool operator == (const CBox& aBox) const
	{
		return this->Volume() == aBox.Volume();
	}
	CBox operator + (const CBox& aBox) const
	{
		return CBox(m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
							m_Width > aBox.m_Width ? m_Width : aBox.m_Width,
							m_Height + aBox.m_Height);
	}
	void ShowBox() const
	{
		cout << m_Length << " " << m_Width << " " << m_Height << endl;
	}
private:
	double m_Length;
	double m_Width;
	double m_Height;
};
inline bool operator > (const double& value, const CBox& aBox)
{
	return value > aBox.Volume();
}
int main(void)
{
	CBox smallBox(4.0, 2.0, 1.0);
	CBox mediumBox(10.0, 4.0, 2.0);
	CBox aBox;
	CBox bBox;
	cout << "smallBox dimensions are ";
	smallBox.ShowBox();
	cout << "mediumBox dimensions are ";
	mediumBox.ShowBox();
	aBox = smallBox + mediumBox;
	cout << "aBox = smallBox + mediumBox. Dimensions are ";
	aBox.ShowBox();
	bBox = aBox + smallBox + mediumBox;
	cout << "bBox = aBox + smallBox + mediumBox. Dimensions are ";
	bBox.ShowBox();
	return 0;
}


