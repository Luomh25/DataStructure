#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
void BiBubble(int r[], int n);

int main()
{
    int a[Max + 1], i = 0;
	Creat(a, Max);
	cout<<"for unordered list: ";
    for (i = 0; i < Max; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	BiBubble(a, Max);
	cout<<"after perform Bibubble: ";
    for (i = 0; i < Max; i++)
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

void BiBubble(int r[],int n) 
{
	int flag = 1,i = 0, j;
	while(flag == 1)
	{
		flag = 0;
		for(j = n-i-1; j > i; j--)
		{
			if(r[j-1] > r[j])
			{
				flag = 1;
				int t = r[j];
				r[j] = r[j-1];
				r[j-1] = t;
			}
		}
		for(j = i+1; j < n-i-1; j++)
		{
			if(r[j] > r[j+1])
			{
				flag = 1;
				int t = r[j];
				r[j] = r[j+1];
				r[j+1] = t;
			}			
		}
		i++;
	}
}