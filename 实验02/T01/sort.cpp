#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int n=10;
void sort(int A[])
{
    int i,j,k;
    int t;
    for ( i = 1; i <= n; i++)
    {
        k=i;
        for ( j = i+1; j <= n; j++)
            if (A[j]<A[k]) k=j;
        t=A[k];
        A[k]=A[i];
        A[i]=t;
    }
}
void show(int A[])
{
    for (int i = 1; i <= n; i++)
        cout<<A[i]<<" ";
    cout<<endl;    
}
void get(int A[])
{
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
        A[i]=1+rand()%10000;
}
int main()
{
    int A[n+1];
    get(A);
    sort(A);
    show(A);
    cout<<"max="<<A[n]<<",vice-max="<<A[n-1]<<endl;
    return 0;
}