#include <iostream>
#include <cstdio>
using namespace std;
#include "LinkStack.cpp"

int main()
{
    int a,k;
    cout<<"����ʮ��������"<<endl;
    cin>>a;
    cout<<"�����ת���Ľ��ƣ����֣���"<<endl;
    cin>>k;
    LinkStack<int> S(a,k);
    cout<<"ת�����Ϊ��"<<endl;
    while(S.Empty() != 1)
    {
        cout<<S.Pop();
    }
    return 0;
}