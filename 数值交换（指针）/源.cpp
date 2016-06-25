#include <iostream>
using namespace std;

void swap1(int p, int q)
{
	int temp;
	temp = p;
	p = q;
	q = temp;
}

/*void swap2(int *p, int *q)
{
	int *temp;
	*temp = *p;
	*p = *q;
	*q = *temp;
}*/

void swap3(int *p, int *q)
{
	int *temp;
	temp = p;
	p = q;
	q = temp;
}

void swap4(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void swap5(int &p, int &q)
{
	int temp;
	temp = p;
	p = q;
	q = temp;
}

int main()
{
	int a1, b1, a2, b2, a3, b3, a4, b4, a5, b5;
	cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4>>a5>>b5;
	//swap1(a1, b1);
	//cout<<a1<<" "<<b1<<endl;
	//swap2(&a2, &b2);
	//cout<<a2<<" "<<b2<<endl;
	swap3(&a3, &b3);
	cout<<a3<<" "<<b3<<endl;
	swap4(&a4, &b4);
	cout<<a4<<" "<<b4<<endl;
	swap5(a5, b5);
	cout<<a5<<" "<<b5<<endl;

	return 0;
}