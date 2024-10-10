#include <iostream>
#include <iomanip>
using namespace std;
int a[1000][1000];

void pin(int N, int n, int num)
{
    int istart = (N-n)/2+1;
    int jstart = (N-n)/2+1;
    for (int i = 0; i < n; i++)
    {
        num++;
        a[istart+i][jstart] = num;
    }
    istart = istart + n - 1;
    for (int j = 1; j < n; j++)
    {
        num++;
        a[istart][jstart+j] = num;
    }
    jstart = istart;
    for (int i = 1; i < n; i++)
    {
        num++;
        a[istart-i][jstart] = num;
    }
    istart = (N-n)/2+1;
    for (int j = 1; j < n-1; j++)
    {
        num++;
        a[istart][jstart-j] = num;
    }
    if (n-2 > 0) pin(N,n-2,num);
}

int main()
{  
	int N=9;
	pin(N,N,0);
	for(int i=1;i<=N;i++) 
	{
		for(int j=1;j<=N;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
   	return 0; 
}
