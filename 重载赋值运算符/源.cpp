#include<iostream>
#include<cstring>
using namespace std;
class CMessage
{
private:
	char* pmessage;
public:
	void ShowIt() const
	{
		cout << endl << pmessage;
	}
	void Reset()
	{
		char* temp = pmessage;
		while(*temp)
			*(temp++) = '*';
	}
	CMessage& operator=(const CMessage& aMess)
	{
		if (this != &aMess)
		{
			delete [] pmessage;
			pmessage = new char[strlen(aMess.pmessage)+1];
			strcpy_s(this->pmessage,strlen(aMess.pmessage)+1,aMess.pmessage);
		}
		return *this;
	}
	CMessage(const char* text="Default message")
	{
		pmessage = new char[strlen(text)+1];
		strcpy_s(pmessage, strlen(text)+1, text);
	}
	CMessage(const CMessage& aMess)
	{
		size_t len = strlen(aMess.pmessage) + 1;
		pmessage = new char[len];
		strcpy_s(pmessage, len, aMess.pmessage);
	}
	~CMessage()
	{
		cout << "Destructor called."
				<< endl;
		delete [] pmessage;
	}
};
int main()
{
	CMessage motto1("The devil takes care of his own");
	CMessage motto2;
	cout << "motto2 contains -";
	motto2.ShowIt();
	cout << endl;
	motto2 = motto1;
	cout << "motto2 contains -";
	motto2.ShowIt();
	cout << endl;
	motto1.Reset();
	cout << "motto1 now contains -";
	motto1.ShowIt();
	cout << endl;
	cout << "motto2 still contains -";
	motto2.ShowIt();
	cout << endl;
	return 0;
}