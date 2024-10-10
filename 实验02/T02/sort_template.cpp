#include <iostream>
using namespace std;
const int n=10;
template<typename T>
void sort(T A[])
{
    int i,j,k;
    T t;
    for ( i = 1; i <=n; i++)
    {
        k=i;
        for ( j = i+1; j <= n; j++)
            if (A[j]<A[k]) k=j;
        t=A[k];
        A[k]=A[i];
        A[i]=t;
    }
}
template<typename T>
void show(T A[])
{
    for (int i = 1; i <= n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
    cout<<"max="<<A[n]<<",vice-max="<<A[n-1]<<endl;
}
int main()
{
    int A1[n+1];
    double A2[n+1];
    long A3[n+1];
    cout<<"type in:"<<endl;

    for (int i = 1; i <=n ; i++)
        cin>>A1[i];
    for (int i = 1; i <=n ; i++)
        cin>>A2[i];
    for (int i = 1; i <=n ; i++)
        cin>>A3[i];
    cout<<"output:"<<endl;
    sort(A1);
    show(A1);
    sort(A2);
    show(A2);
    sort(A3);
    show(A3);
    return 0;
}