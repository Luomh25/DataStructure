#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
int QuickPass(int r[], int first, int end);
void QuickSort(int r[], int n);
void show(int r[], int n);

int main()
{
    int a[Max + 1] = { 0, 2, 8, 1, 3, 7, 10, 6, 4, 5, 10};
    int i = 0;
    Creat(a, Max);
    cout<<"for unordered list: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    QuickSort(a, Max);
    cout<<"after perform QuickSort: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
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

int QuickPass(int r[], int first, int end)
{
    int i = first, j = end;
    while (i < j)
    {
        while (i < j && r[i] <= r[j])
            j--;
        if (i < j)
        {
            r[0] = r[i];
            r[i] = r[j];
            r[j] = r[0];
            i++;
        }
        while (i < j && r[i] <= r[j])
            i++;
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

void QuickSort(int r[], int n)
{
    int top = -1, S[Max + 1];
    int low = 1, high = n, i, thigh = n;
    while (low < high || top != -1)
    {
        while (low < high)
        {
            i = QuickPass(r, low, high);
            //cout<<"low: "<<low<<", high: "<<high<<", i: "<<i<<endl;
            ++top;
            S[top] = i;
            high = i - 1;
        }
        if (top != -1)
        {
            i = S[top];
            top--;
            low = i + 1;
            high = n;
            //cout<<"low: "<<low<<", high: "<<high<<", i: "<<i<<endl;
        }
    }
}

void show(int r[], int n)
{
    for (int i = 1; i <= Max; i++)
        cout<<r[i]<<" ";
    cout<<endl;
}