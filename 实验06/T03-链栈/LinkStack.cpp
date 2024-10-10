#include <iostream>
using namespace std;
#include "LinkStack.h"

template <class DataType>
LinkStack<DataType>::LinkStack( )
{
	top=NULL;//��ͷ���
}

template <class DataType>
LinkStack<DataType> :: ~LinkStack()
{   
	Node<DataType> *q;
	while (top != NULL)        	 //�ͷŵ������ÿһ�����Ĵ洢�ռ�
	{	
		q = top;                 //�ݴ汻�ͷŽ��
		top = top -> next;       //firstָ���ͷŽ�����һ�����
		delete q;
	}
}

template <class DataType> 
void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType> *s;
	s = new Node<DataType>;     //ֱ���Լ��׳��쳣 
	if(s == NULL) throw "����"; 
	s -> data = x;              //����һ��������Ϊx�Ľ��
	s -> next = top; 
	top = s;                    //�����ŵ�ջ�� 
}

template <class DataType>
DataType LinkStack<DataType>::Pop( )
{ 
    DataType x;   
	Node<DataType> *p;
    if (top == NULL) throw "����";
    x = top -> data; 
	p = top;
    top = top -> next;			//topָ���ƶ� 
    delete p;
    return x;
}

template <class DataType> 
DataType LinkStack<DataType>::GetTop( )
{
	if (top != NULL)  
    	return top -> data;
    else
		throw "��"; 
}

template <class DataType> 
int LinkStack<DataType>::Empty( )
{
	if(top == NULL) return 1;
	else return 0;
} 
