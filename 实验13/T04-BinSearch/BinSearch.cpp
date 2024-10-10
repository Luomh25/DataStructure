#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

const int Max = 10;
int a[Max + 1] = {0};
void Creat();
int BinSearch(int r[], int n, int k, int &count);

int main()
{
    int location = 0, count = 0, k;
    Creat();
    for (int i = 1; i <= Max; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    k = a [1 + rand() % Max];
    location = BinSearch(a, Max, k, count);
    cout<<"元素"<<k<<"在序列中的序号是"<<location;
    cout<<"，共比较"<<count<<"次"<<endl;
    return 0;
}

void Creat()
{
    srand(time(NULL));
    a[0] = 0;
    for (int i = 1; i <= Max; i++)
        a[i] = a[i-1] + rand() % Max;
}

int BinSearch(int r[], int n, int k, int &count)
{
    int low = 1, high = n;
    int mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        count++;
        if (k < r[mid]) high = mid - 1;
        else return mid;
    }
    return 0;
}