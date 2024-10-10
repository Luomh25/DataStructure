#include <iostream>
#include "LinkList.h"
using namespace std;

template <class DataType>
LinkList<DataType> :: LinkList( )
{
	Node<DataType> *first = new Node<DataType>;                       
	first->next = first;
	rear = first;
}

template <class DataType>  
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
	Node<DataType> *first,*r, *s;
	first = new Node<DataType>;                 
	r = first;                          
	for (int i = 0; i < n; i++)
	{ 
		s = new Node<DataType>;
		s -> data = a[i];       
		r -> next = s;
		r = s;        
	}
	rear = r;
	rear -> next = first; 
}

template <class DataType>
LinkList<DataType> :: ~LinkList( )
{
	Node<DataType> *q,*first;
	first = rear -> next;
	while (first != rear)       
	{
		q = first;                 
		first = first->next;        
		delete q;    
	}
	delete first;
}

template <class DataType> 
int LinkList<DataType> ::Length( )
{
	Node<DataType> *p = (rear -> next) -> next;  
	int l=0;
	while(p!=rear -> next)
	{
		l++;
		p=p->next;
	}
	return l;
}

template <class DataType>  
void LinkList<DataType> :: Insert(int i, DataType x)
{
	if(i > Length() + 1) throw i;
	Node<DataType> *p, *s;
	int count = 0; 
	p = rear -> next;              
	while (count < i-1)  
	{
		p = p -> next;
		count++;
	}
	s=new Node<DataType>;
	s -> data = x;
	s -> next = p->next;
	p -> next = s;
	if(i==Length()) rear=s;
}

template <class DataType>  
void LinkList<DataType> :: Delete(int i)
{
	if (i > Length()) throw i;
	Node<DataType> *p, *d;
	DataType x;
	int count = 0; 
	p = rear -> next;               
	while (count < i - 1)  
	{
		p = p -> next;
		count++;
	}
	if(count==Length()-1) rear=p; 
	d = p->next;  
	p->next = d->next;             
	delete d; 
	return ;
}

template <class DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
	Node<DataType> *p = rear -> next -> next;
	int count = 1;        
	while (p != rear -> next)    
	{
		if (p->data == x) 
			return count;     
		p = p->next;                   
		count++;
	}
	return 0;                        
}

template <class DataType>
void LinkList<DataType> :: PrintList( )
{
	Node<DataType> *p = rear -> next -> next;
	while (p != rear -> next)
	{
		cout << p->data<<"  ";
		p = p->next;                
	}
	cout<<endl;
}

