#include <iostream>
using namespace std;
#include "LinkList.h"

int main()
{
	int n=0,m=0;
	//����ʽA 
	cout<<"����ʽA��"<<endl;
	cout<<"���������ʽ��������";
	cin>>n;
	double a1[n];
	int b1[n];
	cout<<"�밴��������������ÿһ���ϵ���ʹ�����"<<endl;
	for(int i = 0;i < n;i++)
	{ 
		cout<<"��"<<(i+1)<<"�";
	  	cin>>a1[i];
	  	cin>>b1[i];
	  	cout<<endl;
	}
	LinkList A(a1,b1,n);
	//����ʽB 
	cout<<"����ʽB��"<<endl;
	cout<<"���������ʽ��������";
	cin>>m;

	double a2[m];
	int b2[m];
	cout<<"�밴��������������ÿһ���ϵ���ʹ�����"<<endl;
	for(int j = 0;j < m;j++)
	{ cout<<"��"<<(j+1)<<"�";
	  cin>>a2[j];
	  cin>>b2[j];
	  cout<<endl;
	}
	LinkList B(a2,b2,m);
	//A+B
	cout<<"��֪��"<<endl;
	cout<<"A=";A.PrintList();
	cout<<endl;
	cout<<"B=";B.PrintList();
	cout<<endl;
	Add(A,B);
	cout<<"��A+B=";
	A.PrintList();
	return 0;
}
