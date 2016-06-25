#include<iostream>
using namespace std;
struct RECTANGLE
{
	int Left;
	int Top;
	int Right;
	int Bottom;
};
long Area(const RECTANGLE& aRect);
void MoveRect(RECTANGLE& aRect, const int& x, const int& y);
int main(void)
{
	RECTANGLE Yard = {0, 0, 100, 120};
	RECTANGLE Pool = {30, 40, 70, 80};
	RECTANGLE Hut1, Hut2;
	Hut1.Left = 70;
	Hut1.Top = 10;
	Hut1.Right = Hut1.Left + 25;
	Hut1.Bottom = 30;
	Hut2 = Hut1;
	MoveRect(Hut2, 10, 90);
	cout << endl
		 << "Coordinates of Hut2 are"
		 << Hut2.Left << "," << Hut2.Top << "and"
		 << Hut2.Right << "," << Hut2.Bottom;
	cout << endl
		 << "The area of the yard is " << Area(Yard);
	cout << endl
		 << "The area of the pool is " << Area(Pool)
		 << endl; 
	return 0;
}
long Area(const RECTANGLE& aRect)
{
	return (aRect.Right - aRect.Left) * (aRect.Bottom - aRect.Top);
}
void MoveRect(RECTANGLE& aRect, const int& x, const int& y)
{
	int length(aRect.Right - aRect.Left);
	int width(aRect.Bottom - aRect.Top);
	aRect.Left = x;
	aRect.Top = y;
	aRect.Right = x + length;
	aRect.Bottom = y + width;
	return;
}