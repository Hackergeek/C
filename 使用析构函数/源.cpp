#include<iostream>
#include <cstring>
using namespace std;
class CMessage
{
public:
	~CMessage();
	CMessage(const char* text = "Defaulet message")
	{
		pmessage = new char[strlen(text)+1];
		strcpy_s(pmessage,strlen(text)+1,text);
	}
	void ShowIt() const
	{
		cout << endl << pmessage;
	}
private:
	char* pmessage;
};
 CMessage::~CMessage()
 {
	 cout << "Destructor called" << endl;
	 delete [] pmessage;
 }
int main()
 {
	 // Declare object
	 CMessage motto("A miss is as good as a mile.");

	 // Dynamic object
	 CMessage* pM(new CMessage("A cat can look at a queen."));

	 motto.ShowIt();                                  // Display 1st message
	 pM->ShowIt();                                    // Display 2nd message
	 cout << endl;

	 delete pM;                                      // Manually delete object created with new
	 return 0;
 }