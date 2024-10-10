#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
void SelectSort(int r[], int n);
void Sift(int r[], int k, int m);
void HeapSort(int r[], int n);

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
    SelectSort(a, Max);
    cout<<"after perform straight selection: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"for unordered list: ";
    for ( i = 1; i <= Max ; i++)
        cout<<b[i]<<" ";
    cout<<endl;
    HeapSort(b, Max);
    cout<<"after perform Heapsort: ";
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

void SelectSort(int r[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int index = i;
        for (int j = i + 1; j <= n; j++)
            if (r[j] < r[index])  index = j;
        if (index != i)
        {
            r[0] = r[i];
            r[i] = r[index];
            r[index] = r[0];
        }
    }
}

void Sift(int r[], int k, int m)
{
    int i = k, j = 2 * i;
    while (j <= m)
    {
        if (j < m && r[j] < r[j + 1])  j++;
        if (r[i] > r[j])  break;
        else
        {
            r[0] = r[i];
            r[i] = r[j];
            r[j] = r[0];
            i = j;
            j = 2 * i;
        }
    }
}

void HeapSort(int r[], int n)
{
    int i = 0;
    for ( i = n/2; i >= 1; i--)
        Sift(r, i, n);
    for ( i = 1; i < n; i++)
    {
        r[0] = r[1];
        r[1] = r[n - i + 1];
        r[n - i + 1] = r[0];
        Sift(r, 1, n-i);
    }
}