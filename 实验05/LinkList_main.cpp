#include <iostream>
using namespace std;
#include "LinkList.h"

int main()
{
	int n=0,m=0;
	//多项式A 
	cout<<"多项式A："<<endl;
	cout<<"请输入多项式的项数：";
	cin>>n;
	double a1[n];
	int b1[n];
	cout<<"请按照升幂依次输入每一项的系数和次数："<<endl;
	for(int i = 0;i < n;i++)
	{ 
		cout<<"第"<<(i+1)<<"项：";
	  	cin>>a1[i];
	  	cin>>b1[i];
	  	cout<<endl;
	}
	LinkList A(a1,b1,n);
	//多项式B 
	cout<<"多项式B："<<endl;
	cout<<"请输入多项式的项数：";
	cin>>m;

	double a2[m];
	int b2[m];
	cout<<"请按照升幂依次输入每一项的系数和次数："<<endl;
	for(int j = 0;j < m;j++)
	{ cout<<"第"<<(j+1)<<"项：";
	  cin>>a2[j];
	  cin>>b2[j];
	  cout<<endl;
	}
	LinkList B(a2,b2,m);
	//A+B
	cout<<"已知："<<endl;
	cout<<"A=";A.PrintList();
	cout<<endl;
	cout<<"B=";B.PrintList();
	cout<<endl;
	Add(A,B);
	cout<<"则A+B=";
	A.PrintList();
	return 0;
}
