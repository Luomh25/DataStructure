#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
void BubbleSort(int r[], int n);
int Partition(int r[], int first, int end);
void QuickSort(int r[], int first, int end);

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
    BubbleSort(a, Max);
    cout<<"after perform BubbleSort: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"for unordered list: ";
    for ( i = 1; i <= Max ; i++)
        cout<<b[i]<<" ";
    cout<<endl;
    QuickSort(b, 1, Max);
    cout<<"after perform QuickSort: ";
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

void BubbleSort(int r[], int n)
{
    int exchange = n, bound = n;
    while (exchange != 0)
    {
        bound = exchange;
        exchange = 0;
        for (int j = 0; j < bound; j++)
            if (r[j] > r[j + 1])
            {
                r[0] = r[j];
                r[j] = r[j + 1];
                r[j + 1] = r[0];
                exchange = j;
            }    
    }
}

int Partition(int r[], int first, int end)
{
    int i = first, j = end;
    while (i < j)
    {
        while (i < j && r[i] <= r[j])  j--;
        if (i < j)
        {
            r[0] = r[i];
            r[i] = r[j];
            r[j] = r[0];
            i++;
        }
        while (i < j && r[i] <= r[j])  i++;
        if (i < j)
        {
            r[0] = r[i];
            r[i] = r[j];
            r[j] = r[0];
            j--;
        }
    }
    return i;
}

void QuickSort(int r[], int first, int end)
{
    if (first < end)
    {
        int pivot = Partition(r, first, end);
        QuickSort(r, first, pivot - 1);
        QuickSort(r, pivot + 1, end);
    }
}