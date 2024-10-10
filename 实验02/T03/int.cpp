#include <iostream>
#include <cstdio>
using namespace std;
const int n = 10;
void inverse(int A[],int sta,int end)
{
    int i=sta,j=end;
    while (i<j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}
void move(int A[],int k)
{
    inverse(A,1,k);
    inverse(A,k+1,n);
    inverse(A,1,n);
}
void show(int A[])
{
    for (int i = 1; i <= n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
void get(int A[])
{
    cout<<"输入10个数字"<<endl;
    for (int i = 1; i <= n; i++)
        cin>>A[i];
}
int main()
{
    int A[n+1],k;
    get(A);
    cout<<"输入k"<<endl;
        cin>>k;
    k=k%n;
    move(A,k);
    show(A);
    return 0;
}