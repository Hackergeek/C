#include<iostream>
#include<utility>
using namespace std;
class CBox                             // Class definition at global scope
{
public:
	// Constructor definition
	explicit CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0) : m_Height(hv)
	{
		m_Length = std::max(lv, wv);
		m_Width = std::min(lv, wv);

		// Length is now greater than or equal to width 
		if(m_Height > m_Length)
		{
			m_Height = m_Length;
			m_Length = hv;

			// m_Height is still greater than m_Width so swap them
			double temp = m_Width;
			m_Width = m_Height;
			m_Height = temp;
		}
		else if( m_Height > m_Width)
		{
			m_Height = m_Width;
			m_Width = hv;
		}
	}
	// Function to calculate the volume of a box
	double Volume() const
	{
		return m_Length*m_Width*m_Height;
	}

	// Operator function for 'less than' that
	// compares volumes of CBox objects.
	bool operator<(const CBox& aBox) const
	{
		return this->Volume() < aBox.Volume();
	}

	// 'Less than' operator function to compare a CBox object volume with a constant
	bool operator<(const double& value) const
	{
		return this->Volume() < value;
	}

	// 'Greater than' function to compare a CBox object volume with a constant
	bool operator>(const double& value) const
	{
		return this->Volume() > value;
	}

	// Overloaded equality operator
	bool operator==(const CBox& aBox) const
	{
		return this->Volume() == aBox.Volume();
	}

	// Function to add two CBox objects
	CBox operator+(const CBox& aBox) const
	{
		// New object has larger length & width, and sum of heights
		return CBox(m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
			m_Width > aBox.m_Width   ?  m_Width : aBox.m_Width,
			m_Height + aBox.m_Height);
	}

	// Function to show the dimensions of a box
	void ShowBox() const
	{
		cout << m_Length << " " << m_Width  << " " << m_Height << endl;
	}

private:
	double m_Length;                   // Length of a box in inches
	double m_Width;                    // Width of a box in inches
	double m_Height;                   // Height of a box in inches
};
template<class T> class CSamples
{
public:
	CSamples(const T values[], int count);
	CSamples(const T& value);
	CSamples(T&& value);
	CSamples() : m_Free(0) {  }
	bool Add(const T& value);
	bool Add(T&& value);
	T Max() const;
private:
	template<class T>CSamples<T>::CSamples(const T values[], int count)
	{
		m_Free = count < 100 ? count : 100;
		for (int i = 0; i < m; i++)
		{
			m_Values[i] = values[i];
		}
	}
	template<class T> CSamples<T>::CSamples(T& value)
	{
		m_Values[0] = value;
		m_Free = 1;
	}
	template<class T> CSamples<T>::CSamples(T&& value)
	{
		cout << "Move constructor." << endl;
		m_Values[0] = move(value);
		m_Free = 1;
	}
	template<class T> CSamples<T>::Add(const T& value)
	{
		cout << "Add." << endl;
		bool OK = m_Free < 100;
		if (OK)
		{
			m_Values[m_Free++] = value;
		}
		return OK;
	}
	template<class T> CSamples<T>::Add(T&& value)
	{
		cout << "Add move." << endl;
		bool OK = m_Free < 100;
		if (OK)
		{
			m_Values[m_Free++] = move(value);
		}
		return OK;
	}
	template<class T> CSamples<T>::Max() const
	{
		T theMax = m_Values[0];
		for (int i = 1; i < m_Free; i++)
		{
			if (theMax < m_Values[i])
			{
				theMax = m_Values[i];
			}
		}
		return theMax;
	}
};
int main(void)
{
	CBox boxes[] = {
		CBox(8.0, 5.0, 2.0),
		CBox(5.0, 4.0, 6.0),
		CBox(4.0, 3.0, 3.0)
	};

	return 0;
}