#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <time.h>
using namespace std;

const int Max = 8;
const int Max2 = Max + 1;

void Creat(int r[], int n);
void InsertHeap(int r[],int k);
void Sift(int r[], int k, int m);

int main()
{
    int a[Max2 + 1] = {0,26,47,26,35,19,13,7,18,0};
	
	int i = 0;
	Creat(a, Max2);
	for(i = Max/2; i >= 1; i--)
		Sift(a,i,Max);

	cout<<"初始的大根堆为：";
    for (i = 1; i <= Max; i++)
		cout<<a[i]<<"  ";
	cout<<endl;

	a[Max2]=a[Max2]%30;		
	cout<<"插入"<<a[Max2]<<", 大根堆为：";
    
	InsertHeap(a,Max);
	
	for (i = 1; i <= Max2; i++)
		cout<<a[i]<<"  ";	
	return 0;
}

void Creat(int r[], int n)
{
    int i = 0;
    srand(time(NULL));
    for ( i = 1; i <= n; i++)
        r[i] = 1 + rand() % 100;
}

void InsertHeap(int r[],int k)
{
	int x = r[k+1];
	int i = k+1;
	while(i/2 > 0 && r[i/2] > x)
	{
		r[i] = r[i/2];
		i = i/2;
	}
	r[i] = x;
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