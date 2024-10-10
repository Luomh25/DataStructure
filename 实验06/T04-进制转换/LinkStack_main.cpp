#include <iostream>
#include <cstdio>
using namespace std;
#include "LinkStack.cpp"

int main()
{
    int a,k;
    cout<<"输入十进制数："<<endl;
    cin>>a;
    cout<<"输入待转换的进制（数字）："<<endl;
    cin>>k;
    LinkStack<int> S(a,k);
    cout<<"转换结果为："<<endl;
    while(S.Empty() != 1)
    {
        cout<<S.Pop();
    }
    return 0;
}