#include <iostream>
using namespace std;
#include "LinkStack.h"

template <class DataType>
LinkStack<DataType>::LinkStack( )
{
	top=NULL;//无头结点
}

template <class DataType>
LinkStack<DataType> :: ~LinkStack()
{   
	Node<DataType> *q;
	while (top != NULL)        	 //释放单链表的每一个结点的存储空间
	{	
		q = top;                 //暂存被释放结点
		top = top -> next;       //first指向被释放结点的下一个结点
		delete q;
	}
}

template <class DataType> 
void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType> *s;
	s = new Node<DataType>;     //直接自己抛出异常 
	if(s == NULL) throw "上溢"; 
	s -> data = x;              //申请一个数据域为x的结点
	s -> next = top; 
	top = s;                    //将结点放到栈顶 
}

template <class DataType>
DataType LinkStack<DataType>::Pop( )
{ 
    DataType x;   
	Node<DataType> *p;
    if (top == NULL) throw "下溢";
    x = top -> data; 
	p = top;
    top = top -> next;			//top指针移动 
    delete p;
    return x;
}

template <class DataType> 
DataType LinkStack<DataType>::GetTop( )
{
	if (top != NULL)  
    	return top -> data;
    else
		throw "空"; 
}

template <class DataType> 
int LinkStack<DataType>::Empty( )
{
	if(top == NULL) return 1;
	else return 0;
} 
