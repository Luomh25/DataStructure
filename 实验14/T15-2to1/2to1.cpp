#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int N = 10;
const int M = 5;
void Creat(int r[], int n);
void Union(int A[], int n, int B[], int m, int C[]);

int main()
{
	int A[N], B[M], C[N+M];
	int i = 0;
	Creat(A, N);
	cout<<"A: ";
    for (i = 0; i < N; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	Creat(B, M);
	cout<<"B: ";
    for (i = 0; i <M; i++)
		cout<<B[i]<<"  ";
	cout<<endl;
	Union(A, N, B, M, C);
	cout<<"after Union, C: "<<endl;
    for (i = 0; i < M + N; i++)
		cout<<C[i]<<" ";
	cout<<endl;
	return 0;
}

void Creat(int r[], int n)
{
	int i = 0;
	srand(time(NULL)+n);
	for (i = 0; i < n; i++) 
	{
		if(i==0)  r[i] = 1 + rand() % 100;
		else  r[i] = r[i-1] + rand() % 20;
	}	
}

void Union(int A[], int n, int B[], int m, int C[])
{
	int i = 0, j = 0, k = 0;
	while(i < n && j < m)
	{
		if(A[i]<=B[j])  C[k++] = A[i++];
		else  C[k++] = B[j++];
	}
	while(i < n)  C[k++] = A[i++];
	while(j < m)  C[k++] = B[j++];
}