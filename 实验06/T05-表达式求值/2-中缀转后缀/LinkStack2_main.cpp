#include<iostream>
using namespace std;
#include "LinkStack2.cpp" 

int main()
{
    try
	{
		while (1) Run();
	}
	catch (const char *s)
	{
		cout << s << endl;
	}
    return 0;
}