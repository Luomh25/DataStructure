#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
using namespace std;
const int N = 100;

int main()
{  
	int count=0;
	char S[1024];
	gets(S);
	int i=0;
	while(1) 
	{
		if(S[i]=='\0')
		{
			char a=S[i-1];
			if(a!=' ') count++;
			break;
		}
		if(S[i]==' '&&i>=1)
		{
			char a=S[i-1];
			if(a!=' ') count++;			
		}
		i++;
	}
	cout<<count;
}