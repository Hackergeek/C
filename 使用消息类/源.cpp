#include<iostream>
#include<cstring>
using namespace std;
class CMessage
{
private:
	char* pmessage;
public:
	void ShowIt()
	{
		cout << endl << pmessage;
	}
	CMessage(const char* text = "Default message")
	{
		pmessage = new char[strlen(text) + 1];
		strcpy_s(pmessage, strlen(text) + 1, text);
	}
	~CMessage()
	{
		delete [] pmessage;
		cout << "Done!" << endl;
	}
};
int main(void)
{
	CMessage good_new("I pass the exam!");
	CMessage* pm =new CMessage("congratulation");
	good_new.ShowIt();
	pm->ShowIt();
	cout << endl;
	delete pm;
	return 0;
}