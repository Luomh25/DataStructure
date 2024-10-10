#include<iostream>
using namespace std;
#include "SeqList.h"

int main()
{
	int r[5]={29,31,3,67,2};
	int a,b;
	SeqList L(r,5);
	cout<<"执行插入操作前数据为："<<endl;
	L.PrintList();
	cout<<"此时数组长度为："<<sizeof(r)/sizeof(r[0])<<endl; 
	cout<<"请输入插入的位置："<<endl;
	cin>>a;
	cout<<"请输入插入的数据："<<endl;
	cin>>b;
	try
	{
		L.Insert(a,b);
	}
	catch(char*s)
	{
		cout<<s<<endl;
	}
	cout<<"执行插入操作后数据为："<<endl;
	L.PrintList();
	cout<<"值为3的元素位置为：";
	cout<<L.Locate(3)<<endl;
	cout<<"执行删除第一个元素操作，删除前数据为："<<endl;
	L.PrintList();
	try
	{
		L.Delete(1);
	}
	catch(char*s)
	{
		cout<<s<<endl;
	}
	cout<<"删除后数据为："<<endl;
	L.PrintList(); 
	return 0;
}
