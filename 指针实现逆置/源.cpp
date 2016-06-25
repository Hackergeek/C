#include <iostream>
#include <stdlib.h>
const int N = 10;
using namespace std;

int main()
{
	char src[N+1];
	cin>>src;
	int len = strlen(src);
	char* dest = new char[len];
	char* s = &src[len-1];  
	char* d = dest; 
	while( len-- != 0 )
		*d++=*s--;
	cout<<dest<<endl;
	dest = NULL;
	return 0;
}