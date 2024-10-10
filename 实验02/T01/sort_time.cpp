#include <iostream>
#include <stdlib.h>
#include <time.h>
#define CLOCKS_PER_SEC 1000
using namespace std;
const int n=10000;   
void sort(int A[])
{
	int i,j,k;
	int t;
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
			if(A[j]<A[k]) k=j;
		t=A[k];
		A[k]=A[i];
		A[i]=t;
	}
}
void show(int A[])
{		
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
	cout<<endl;		
}
void get(int A[])
{
	srand(time(NULL));
	for(int i=1;i<=n;i++)
		A[i]=1+rand()%10000;
}
int main( )
{
	int A[n+1];
	clock_t start_t, end_t;
	double total_t=0;
	int k=10;
	for(int j=1;j<=10;k=k+10,j++)
	{
		for(int i=1;i<=k;i++)
		{
			get(A); 
			start_t = clock();	//开始时间
			sort(A);
			end_t = clock();	//结束时间
			total_t=total_t-start_t+end_t;
		}
	total_t = (double) total_t / CLOCKS_PER_SEC;	//运行时间
	cout<<"对"<<k<<"组数排序，每组数有"<<n<<"个，所需时间为："<<total_t<<endl;		
	}
	return 0;
}