#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int Max = 20;

void Creat(int r[], int n);
void Merge(int r[], int r1[], int s, int m, int t);
void MergeSort(int r[], int r1[], int n);
void MergePass(int r[], int r1[], int s, int t);

int main()
{
    int r[Max + 1] = {0}, r1[Max + 1] = {0};
    int r2[Max + 1] = {0};
    Creat(r, Max);
    cout<<"for unordered list: "<<endl;
    for (int i = 1; i <= Max ; i++)
        r2[i] = r[i];
    for (int i = 1; i <= Max ; i++)
        cout<<r[i]<<" ";
    cout<<endl;

    MergeSort(r2, r1, Max);
    cout<<"after perform MergeSort: "<<endl;
    for (int i = 1; i <= Max ; i++)
        cout<<r2[i]<<" ";
    cout<<endl;
    return 0;
}

void Creat(int r[], int n)
{
	int i = 0;
	srand(time(NULL));
	for (i = 1; i <= n; i++)
		r[i] = 1 + rand() % 100;
}

void Merge(int r[], int r1[], int s, int m, int t)
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j])  r1[k++] = r[i++];
		else  r1[k++] = r[j++];
	}
	if (i <= m)
		while (i <= m)
			r1[k++] = r[i++];
	else
		while (j <= t)
			r1[k++] = r[j++];
}

void MergePass(int r[],int r1[],int n,int h)
{
	int i=1;
	while(i<=n-2*h+1)
	{
		Merge(r,r1,i,i+h-1,i+2*h-1);
		i+=2*h;
	}
	if(i<n-h+1)
		Merge(r,r1,i,i+h-1,n);
	else
		for(int k=i;k<=n;k++)
			r1[k]=r[k];	
}


void MergeSort(int r[],int r1[],int n)
{
	int h=1;
	while(h<n)
	{
		MergePass(r,r1,n,h);
		h=2*h;
		MergePass(r1,r,n,h);
		h=2*h;
	}
}