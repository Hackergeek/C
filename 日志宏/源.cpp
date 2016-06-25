#include<stdio.h>
#include<time.h>
#define LOG(s) do{												\
	time_t t;															\
	struct tm* ti;														\
	time(&t);															\
	ti = localtime(&t);												\
	printf("%s [%d %s] %s\n", asctime(ti), _FILE_, _LINE_,  s);						\
	}while(0)
int main(void)
{
	LOG("Enter main()...");
	LOG("Exit main()...");
	return 0;
}
