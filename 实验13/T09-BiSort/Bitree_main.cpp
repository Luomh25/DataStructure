#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Bitree.cpp"

const int I = 1000000;
void Bubble(int a[], int len);
void Creat(int a[], int len);

int main()
{
	int a[Len] = {0}, b[Len] = {0};
	clock_t start, end;
	start = clock();
	for (int i = 0; i < I; i++)
	{
		Creat(a, Len);
		for (int j = 0; j < Len; j++)  b[j] = a[j];
		Bubble(b, Len);
		Bitree T1(a, Len), T2(b, Len);
	}
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	for (int i = 0; i < I; i++)
	{
		Creat(a, Len);
		for (int j = 0; j < Len; j++)  b[j] = a[j];
		Bubble(b, Len);
		Bitree T1(a, Len), T2(b, Len);
		for (int i = 0; i < Len; i++)  T1.Search(a[i]);
	}
	end = clock();
	double time1 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	for (int i = 0; i < I; i++)
	{
		Creat(a, Len);
		for (int j = 0; j < Len; j++)  b[j] = a[j];
		Bubble(b, Len);
		Bitree T1(a, Len), T2(b, Len);
		for (int i = 0; i < Len; i++)  T2.Search(b[i]);
	}
	end = clock();
	double time2 = (double)(end - start) / CLOCKS_PER_SEC;

	cout<<time<<endl<<time1<<endl<<time2<<endl;
	double avg1 = (time1 - time)/I;
	double avg2 = (time2 - time)/I;

	cout<<I<<"次查找随机情况平均时间为"<<avg1<<"秒"<<endl;
	cout<<I<<"次查找最坏情况平均时间为"<<avg2<<"秒"<<endl;
	return 0;
}

void Creat(int a[], int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		a[i] = 1 + rand() % 100;
		for (int j = 0; j < i; j++)
			if (a[i] == a[j])  a[i]++;
	}
}

void Bubble(int a[], int len)
{
	int temp;
	for (int j = 0; j < len; j++)
		for (int i = 1; i < len - j; i++)
		{
			if (a[i] > a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
}
