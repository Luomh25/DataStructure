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
    cout<<"����ԭʼ�ַ�����"<<endl;
    cin>>a;
    cout<<"�����ƶ���k��"<<endl;
    cin>>k;
    Caesar(a,k);
    cout<<"���ܺ��ַ���Ϊ��"<<endl;
    cout<<a;
}