#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int BF(const char S[],const char T[])
{
    int i=0,j=0;
    while ((S[i] != '\0') && (T[j] != '\0'))
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (T[j] == '\0') return i-j+1;
    else return 0;
}

int main()
{
    char S[20],T[20];
    cout<<"输入主串S"<<endl;
    cin>>S;
    cout<<"输入子串T"<<endl;
    cin>>T;
    cout<<BF(S,T)<<endl;
}