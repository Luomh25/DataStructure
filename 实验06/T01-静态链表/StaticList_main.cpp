#include<iostream>
using namespace std;
#include "StaticList.cpp"
int main()
{
	StaticList<int>L;
	L.InitList();
	cout<<"�ж������Ƿ�Ϊ�գ�"<<endl; 
	if(L.isEmpty()==1)  
	cout<<"����Ϊ��"<<endl;
	else cout<<"����Ϊ��"<<endl; 
	L.Append(1);
	L.Append(2);
	L.Append(3);
	L.Append(5);
	L.Append(6);
	cout<<"��������Ԫ�غ��ж������Ƿ�Ϊ�գ�"<<endl; 
	if(L.isEmpty()==1)  
	cout<<"����Ϊ��"<<endl;
	else cout<<"����Ϊ��"<<endl; 
	cout<<"Ѱ��Ԫ��3���ڽ��λ��:"<<endl;
	cout<<L.Search(3)<<endl;
	cout<<"��2������Ԫ�ص�ֵΪ��"<<endl;
	cout<<L.Locate(2)<<endl;
	cout<<"ִ�в������������Ϊ��"<<endl;
	L.PrintList();
	L.Insert(4,4);
	cout<<"ִ�в������������Ϊ��"<<endl;
	L.PrintList();
	cout<<"����ĳ���Ϊ��"<<" "<<L.Length()<<endl;
	L.Remove(6);
	cout<<"ִ�в������������Ϊ��"<<endl;
	L.PrintList();
	return 0;
}
