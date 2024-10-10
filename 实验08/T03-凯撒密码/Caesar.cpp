#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void Caesar(string &a,int k)
{
    int l = a.length();
    for (int i = 0; i < l; i++)
    {
        a[i] = 'a' + (a[i] - 'a' + k)%26;
    }
}

int main()
{
    string a;
    int k;
    cout<<"输入原始字符串："<<endl;
    cin>>a;
    cout<<"输入移动量k："<<endl;
    cin>>k;
    Caesar(a,k);
    cout<<"加密后字符串为："<<endl;
    cout<<a;
}