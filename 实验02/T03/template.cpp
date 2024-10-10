#include <iostream>
#include <cstdio>
using namespace std;
const int n=10;
template<typename T>
void inverse(T A[],int sta,int end)
{
    int i=sta,j=end;
    while(i<j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}
template<typename T>
void move(T A[],int k)
{
    inverse(A,1,k);
    inverse(A,k+1,n);
    inverse(A,1,n);
}
template<typename T>
void show(T A[])
{
    for (int i = 1; i <= n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
int main()
{
    int A1[n+1];
    double A2[n+1];
    long long A3[n+1];
    int k;
    cout<<"输入数据："<<endl;
    for (int i = 1; i <= n; i++)
        cin>>A1[i];
    for (int i = 1; i <= n; i++)
        cin>>A2[i];
    for (int i = 1; i <= n; i++)
        cin>>A3[i];
    cout<<"输入左移位数k"<<endl;
        cin>>k;
    k=k%n;
    move(A1,k);
    move(A2,k);
    move(A3,k);
    show(A1);
    show(A2);
    show(A3);
    return 0;
}