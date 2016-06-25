#include<iostream>
#include<cstring>
using namespace std;
class CText
{
private:
	char* pText;
public:
	void ShowIt() const
	{
		cout << pText << endl;
	}
	CText(const char* pStr = "No text")
	{
		cout << "CText constructor called." << endl;
		size_t len = strlen(pStr) + 1;
		pText = new char[len];
		strcpy_s(pText, len, pStr);
	}
	CText(const CText& txt)
	{
		cout << "CText copy constructor called." << endl;
		size_t len = strlen(txt.pText) + 1;
		pText = new char[len];
		strcpy_s(pText, len, txt.pText);
	}
	CText(CText&& txt)
	{
		cout << "CText move constructor called." << endl;
		pText = txt.pText;
		txt.pText = nullptr;
	}
	CText operator+(const CText& txt) const
	{
		cout << "CText add operator function called." << endl;
		size_t len = strlen(pText) + strlen(txt.pText) + 1;
		CText text;
		text.pText = new char[len];
		strcpy_s(text.pText, len, pText);
		strcat_s(text.pText, len, txt.pText);
		return text;
	}
	CText& operator=(const CText& txt) 
	{
		cout << "CText assignment operator function called." << endl;
		if (this != &txt)
		{
			delete [] pText;
			size_t len(strlen(txt.pText) + 1);
			pText = new char[len];
			strcpy_s(pText, len, txt.pText);
		}
		return *this;
	}
	CText& operator=(CText&& txt)
	{
		cout << "CText move assignment operator function called." << endl;
		delete [] pText;
		pText = txt.pText;
		txt.pText = nullptr;
		return *this;
	}
	~CText()
	{
		cout << "CText Destructor called." << endl;
		delete [] pText;
	}
};
class CMessage
{
private:
	CText text;
public:
	void ShowIt() const
	{
		text.ShowIt();
	}
	CMessage operator+(const CMessage& aMess) const
	{
		cout << "CMessage add operator function called." << endl;
		CMessage message;
		message.text = text + aMess.text;
		return message;
	}
	CMessage operator=(const CMessage& aMess)
	{
		cout << "CMessage assignment operator function called." << endl;
		if (this != &aMess)
		{
			text = aMess.text;
		}
		return *this;
	}
	CMessage& operator=(CMessage&& aMess)
	{
		cout << "CMessage move assignment operator function called." << endl;
		text = aMess.text;
		return *this;
	}
	CMessage(const char* str = "Default message")
	{
		cout << "CMessage constructor called." << endl;
		text = CText(str);
	}
	CMessage(const CMessage& aMess)
	{
		cout << "CMessage copy constructor called." << endl;
		text = aMess.text;
	}
	CMessage(CMessage&& aMess)
	{
		cout << "CMessage move constructor called." << endl;
		text = aMess.text;
	}
};
int main(void)
{
	CMessage motto1("The devil takes care of his own.");
	CMessage motto2("If you sup with the devil use a long spoon.\n");
	cout << endl << "Executing: CMessage motto3(motto1 + motto2); " << endl;
	CMessage motto3(motto1 + motto2);
	cout << "Done!! " << endl << endl << "motto3 contains - ";
	motto3.ShowIt();
	CMessage motto4;
	cout << endl << "Executing: CMessage motto4 = motto3 + motto2; " << endl;
	motto4 = motto3 + motto3;
	cout << "Done!! " << endl << endl << "motto4 contains - ";
	motto4.ShowIt();
	cout << endl;
	return 0;
}