#include<iostream>
using namespace std;
#include "SeqList.h"

int main()
{
	int r[5]={29,31,3,67,2};
	int a,b;
	SeqList L(r,5);
	cout<<"ִ�в������ǰ����Ϊ��"<<endl;
	L.PrintList();
	cout<<"��ʱ���鳤��Ϊ��"<<sizeof(r)/sizeof(r[0])<<endl; 
	cout<<"����������λ�ã�"<<endl;
	cin>>a;
	cout<<"�������������ݣ�"<<endl;
	cin>>b;
	try
	{
		L.Insert(a,b);
	}
	catch(char*s)
	{
		cout<<s<<endl;
	}
	cout<<"ִ�в������������Ϊ��"<<endl;
	L.PrintList();
	cout<<"ֵΪ3��Ԫ��λ��Ϊ��";
	cout<<L.Locate(3)<<endl;
	cout<<"ִ��ɾ����һ��Ԫ�ز�����ɾ��ǰ����Ϊ��"<<endl;
	L.PrintList();
	try
	{
		L.Delete(1);
	}
	catch(char*s)
	{
		cout<<s<<endl;
	}
	cout<<"ɾ��������Ϊ��"<<endl;
	L.PrintList(); 
	return 0;
}
