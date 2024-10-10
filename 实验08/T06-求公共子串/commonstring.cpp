#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int common(string a,string b)
{
    int l1=a.length(),l2=b.length();
    for (int i = 0; i < l1; i++)
    {
        int k = 0;
        for (int j = i; j < l1; j++)
        {
            if (a[j] == b[k])
            {
                k++;
                if (k == l2) return 1;
            }
        } 
    }
    return 0;
}

int main()
{
    string a,b;
    cout<<"input S:"<<endl;
    cin>>a;
    cout<<"input T:"<<endl;
    cin>>b;
    cout<<common(a,b);
    return 0;
}