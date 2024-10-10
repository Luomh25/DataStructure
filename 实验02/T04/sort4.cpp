#include <iostream>
#include <cstdio>
using namespace std;
const int n=10;  
void inverse(int A[],int sta,int end)//逆向函数 
{
	int i=sta,j=end;
	while(i<j)
	{
		swap(A[i],A[j]);
		i++;
		j--;
	}
}
void move(int A[])//移动函数 
{
	int i=1,j=n;
	while(i<j)
	{
		while(A[i]%2==1)
			i++;
		while(A[j]%2==0)
			j--;		
		if(i<j)	swap(A[i],A[j]);
	}		
}
void show(int A[])//输出结果 
{		
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
	cout<<endl;		
}
void get(int A[])
{
	cout<<"输入10个数字"<<endl;
	for(int i=1;i<=n;i++)
		cin>>A[i];
}
int main( )
{
	int A[n+1],k;
	get(A);
	move(A);
	show(A); 
	return 0;
}