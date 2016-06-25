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
	CMessage operator+(const CMessage& aMess) const
	{
		cout << "Add operator function called." << endl;
		size_t len = strlen(this->pmessage) + strlen(aMess.pmessage) + 1;
		CMessage message;
		message.pmessage = new char[len];
		strcpy_s(message.pmessage, len, pmessage);
		strcat_s(message.pmessage, len, aMess.pmessage);
		return message;
	}
	CMessage(const CMessage& aMess) 
	{
		cout << "Copy constructor called." << endl;
		pmessage = new char[strlen(aMess.pmessage) + 1];
		strcpy_s(pmessage, strlen(aMess.pmessage) + 1, aMess.pmessage);
	}
	CMessage(const char* text = "Default message")
	{
		cout << "Constructor called." << endl;
		pmessage = new char[strlen(text) + 1];
		strcpy_s(pmessage, strlen(text) + 1, text);
	}
	CMessage& operator=(const CMessage& aMess)
	{
		cout << "Assignment operator function called." << endl;
		if (this != &aMess)
		{
			delete [] pmessage;
			pmessage = new char[strlen(aMess.pmessage) + 1];
			strcpy_s(pmessage, strlen(aMess.pmessage) + 1, aMess.pmessage);
		}
		return *this;
	}
	CMessage& operator=(CMessage&& aMess)
	{
		cout << "Move assignment operator function called." << endl;
		delete [] pmessage;
		pmessage = aMess.pmessage;
		aMess.pmessage = nullptr;
		return *this;
	}
	CMessage(CMessage&& aMess)
	{
		cout << "Move copy constructor called." << endl;
		pmessage = aMess.pmessage;
		aMess.pmessage = nullptr;
	}
	~CMessage()
	{
		cout << "Destructor called." << endl;
		delete [] pmessage;
	}
};
int main(void)
{
	CMessage motto1("The devil takes care of his own.");
	CMessage motto2("If you sup with the devil use a long spoon.\n");
	CMessage motto3;
	cout << "Executing: motto3 = motto1 + motto2 " << endl;
	motto3 = motto1 + motto2;
	cout << "Done!!" << endl << endl;
	cout << "Executing: motto3 = motto3 + motto1 + motto2 " << endl;
	motto3 = motto3 + motto1 + motto2;
	cout << "Done!!" << endl << endl;
	cout << "motto3 contains -";
	motto3.ShowIt();
	cout << endl;
	return 0;
}