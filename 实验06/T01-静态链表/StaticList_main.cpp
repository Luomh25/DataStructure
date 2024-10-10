#include<iostream>
using namespace std;
#include "StaticList.cpp"
int main()
{
	StaticList<int>L;
	L.InitList();
	cout<<"判断链表是否为空："<<endl; 
	if(L.isEmpty()==1)  
	cout<<"链表为空"<<endl;
	else cout<<"链表不为空"<<endl; 
	L.Append(1);
	L.Append(2);
	L.Append(3);
	L.Append(5);
	L.Append(6);
	cout<<"插入上述元素后判断链表是否为空："<<endl; 
	if(L.isEmpty()==1)  
	cout<<"链表为空"<<endl;
	else cout<<"链表不为空"<<endl; 
	cout<<"寻找元素3所在结点位置:"<<endl;
	cout<<L.Search(3)<<endl;
	cout<<"第2个结点的元素的值为："<<endl;
	cout<<L.Locate(2)<<endl;
	cout<<"执行操作后链表输出为："<<endl;
	L.PrintList();
	L.Insert(4,4);
	cout<<"执行操作后链表输出为："<<endl;
	L.PrintList();
	cout<<"链表的长度为："<<" "<<L.Length()<<endl;
	L.Remove(6);
	cout<<"执行操作后链表输出为："<<endl;
	L.PrintList();
	return 0;
}
