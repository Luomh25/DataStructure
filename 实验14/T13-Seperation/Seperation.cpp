#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Max = 10;
void Creat(int r[], int n);
int Devot(int r[], int n);

int main()
{
	int a[Max + 1] = {0};
	int i = 0;
	Creat(a, Max);
	cout<<"for unordered list: ";
	for (i = 0; i < Max; i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	Devot(a, Max);
	cout<<"after perform Seperation: ";
	for (i = 0; i < Max; i++)
		cout<<a[i]<<"  ";
	return 0;
}

void Creat(int r[], int n)
{
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		r[i] = 1 + rand() % 100;
		int t = rand() % 2;
		if (t == 1)
		{
			r[i] = r[i] * (-1);
		}
	}
}
int Devot(int r[], int n)
{
	int i = 0, j = n - 1, t;
	while (i < j)
	{
		while (r[j] > 0 && i < j)
		{
			j--;
		}
		while (r[i] < 0 && i < j)
		{
			i++;
		}

		if (i < j)
		{
			t = r[i];
			r[i] = r[j];
			r[j] = t;
			i++;
			j--;
		}
	}
}
