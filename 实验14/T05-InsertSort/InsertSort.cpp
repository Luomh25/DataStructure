#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
void InsertSort(int r[], int n);
void ShellSort(int r[], int n);

int main()
{
    int a[Max + 1] = {0}, b[Max + 1] = {0};
    int i = 0;
    Creat(a, Max);
    for ( i = 1; i <= Max; i++)
        b[i] = a[i];
    cout<<"for unordered list: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    InsertSort(a, Max);
    cout<<"after perform straight insertion: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"for unordered list: ";
    for ( i = 1; i <= Max ; i++)
        cout<<b[i]<<" ";
    cout<<endl;
    ShellSort(b, Max);
    cout<<"after perform Shell insertion: ";
    for ( i = 1; i <= Max ; i++)
        cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}

void Creat(int r[], int n)
{
    int i = 0;
    srand(time(NULL));
    for ( i = 1; i <= n; i++)
        r[i] = 1 + rand() % 100;
}

void InsertSort(int r[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        r[0] = r[i];
        int j;
        for ( j = i - 1; r[0] < r[j]; j--)
            r[j + 1] = r[j];
        r[j + 1] = r[0];
    }
}

void ShellSort(int r[], int n)
{
    for (int d = n/2; d >= 1; d = d/2)
    {
        for (int i = d + 1; i <= n; i++)
        {
            r[0] = r[i];
            int j;
            for ( j = i - d; j > 0 && r[0] < r[j]; j = j - d)
                r[j + d] = r[j];
            r [j + d] = r[0];
        }
    }
}