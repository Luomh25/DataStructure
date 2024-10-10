#include <iostream>
#include <iomanip>
using namespace std;
int const N = 7;
//修改N值可得不同大小的幻方
void Square(int a[N][N], int n)
{ 
	int i,j,k,iTemp,jTemp;
	i = 0; j = (n - 1) / 2;  
	a[0][j] = 1;                        //在第0行的中间位置填1
	for ( k = 2; k <= n*n; k++)  
	{ 
		iTemp = i; 
		jTemp = j;                      //暂存i,j的值
    	i = (i - 1 + n) % n;            //即i=i-1; if (i<0) i=n-1
    	j = (j - 1 + n) % n;            //即j=j-1; if (j<0) j=n-1
    	if (a[i][j] > 0)
		{ 
			i = (iTemp + 1) % n;        //如果位置(i, j)已经有数，填入同一列下一行
		  	j = jTemp;
		}
    	a[i][j] = k;
  	}
}

void print_Square(int a[N][N],int n)
{  
	int i = 0,j = 0;
	for ( i = 0; i < n; i++)
     {  
        for ( j = 0; j < n; j++)
		    cout<<setw(3)<<a[i][j]<<" ";
        cout<<endl;
	}
}

int main()
{  
	int a[N][N];
	for( int i = 0; i < N; i++)
	{
		for( int j = 0; j < N; j++)
			a[i][j] = 0;
	}
    Square(a,N);
   	print_Square(a,N);
   	return 0;
}