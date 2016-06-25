#include<iostream>
#include<utility>
using namespace std;
using namespace std::rel_ops;
class CBox
{
private:
	double m_Length;
	double m_Height;
	double m_Width;
public:
	explicit CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
	m_Height(hv), m_Length(lv), m_Width(bv)
	{
		cout << endl << "Constructor called.";
	}
	double Volume() const
	{
		return m_Width * m_Length * m_Height;
	}
	bool operator<(const double& value) const
	{
		return this->Volume() < value;
	}
	bool operator==(const CBox& aBox) const
	{
		return this->Volume() == aBox.Volume();
	}
	bool operator>(const double& value) const
	{
		return this->Volume() > value;
	}
	bool operator<(const CBox& aBox) const
	{
		return this->Volume() < aBox.Volume();
	}
	~CBox()
	{
		cout << "Destructor called." << endl;
	}
};
inline bool operator<(const double& value, const CBox& aBox)
{
	return value < aBox.Volume();
}
int main(void)
{
	CBox smallBox(4.0, 2.0, 1.0);
	CBox mediumBox(10.0, 4.0, 2.0);
	CBox otherBox(2.0, 1.0, 4.0);
	if (mediumBox != smallBox)
	{
		cout << endl << "mediumBox is not equal to smallBox.";
	} 
	if (mediumBox > smallBox)
	{
		cout << endl << "mediumBox is bigger than smallBox.";
	}
	else
	{
		cout << endl << "mediumBox is not bigger than smallBox.";
	}
	if (otherBox >= smallBox)
	{
		cout << endl << "otherBox is greater than or equal to smallBox.";
	}
	else
	{
		cout << endl << "otherBox is smaller than smallBox.";
	}
	if (otherBox >= mediumBox)
	{
		cout << endl << "otherBox is greater than or equal to mediumBox.";
	}
	else
	{
		cout << endl << "otherBox is smaller than mediumBox.";
	}
	if (mediumBox > 50.0)
	{
		cout << endl << "mediumBox capacity is more than 50.";
	}
	else
	{
		cout << endl << "mediumBox capacity is not more than 50.";
	}
	if (10.0 < smallBox)
	{
		cout << endl << "smallBox capacity is more than 10.";
	}
	else
	{
		cout << endl << "smallBox capacity is not more than 10.";
	}
	cout << endl;
	return 0;
}