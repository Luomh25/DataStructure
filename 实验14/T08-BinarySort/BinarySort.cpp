#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
void StraightSort(int r[], int n);

int main()
{
    int a[Max + 1] = {0}, b[Max + 1] = {0};
    int i = 0;
    Creat(a, Max);
    cout<<"for unordered list: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    StraightSort(a, Max);
    cout<<"after perform binary-straight insertion: ";
    for ( i = 1; i <= Max ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void Creat(int r[], int n)
{
    int i = 0;
    srand(time(NULL));
    for ( i = 1; i <= n; i++)
        r[i] = 1 + rand() % 100;
}

void StraightSort(int r[], int n)
{   
    int j;
    for (int i = 2; i <= n; i++)
    {
        r[0] = r[i];
        int low = 1, high = i - 1, flag = 1, mid;
        while (low <= high && flag)
        {
            mid = (low + high)/2;
            if (r[0] < r[mid]) high = mid - 1;
            else if (r[0] > r[mid]) low = mid + 1;
                else flag = 0;
        }
        for ( j = i - 1; j >= low; j--)
            r[j + 1] = r[j];
        r[low] = r[0];
    }
}