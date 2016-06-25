#include<iostream>
using namespace std;
class Area
{
private:
public:
	int operator ()(int length, int width)
	{
		return length * width;
	}
};
inline void printArea(int length, int width, Area& area)
{
	cout << endl << "Area is " << area(length, width);
}
int main (void)
{
	Area area;
	int pitchLength(100), pitchWidth(50);
	//int pitchArea = area(pitchWidth, pitchLength);
	//cout << endl << pitchArea;
	printArea(pitchLength, pitchWidth , area);
	cout << endl;
	return 0;
}