#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
int Search(int r[], int n, int j);
int Devo(int r[], int low, int high);

int main()
{
	int a[Max + 1] = {0};
	int i = 0;
	Creat(a, Max);
	cout<<"for unordered list: "<<endl;
	for (i = 1; i <= Max; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"enter j: ";
	int j;cin>>j;
	cout<<"sort from small to large, the data with the index "<<j<<" is ";
    cout<<Search(a, Max, j);
	return 0;
}

void Creat(int r[], int n)
{
	int i = 0;
	srand(time(NULL));
	for (i = 1; i <= n; i++)
		r[i] = 1 + rand() % 100;
}

int Search(int r[], int n, int j)
{
	int s = 1, t = n;
	int k = Devo(r, s, t);
	while (k != j)
	{
		if (k < j)  k = Devo(r, k + 1, t);
		else  k = Devo(r, s, k - 1);
	}
	return r[j];
}

int Devo(int r[], int low, int high)
{
	int i = low, j = high, x = r[low];
	while (i < j)
	{
		while (r[j] >= x && i < j)  j--;
		if (i < j)
		{
			r[i] = r[j];
			i++;
		}
		while (r[i] < x && i < j)  i++;
		if (i < j)
		{
			r[j] = r[i];
			j--;
		}
	}
	r[i] = x;
	return i;
}