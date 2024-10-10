#include <iostream>
#include "LinkList.h"
using namespace std;

template <class DataType>
LinkList<DataType> :: LinkList( )
{
	Node<DataType> *first = new Node<DataType>;                       
	first -> next = NULL;
	first -> prior = NULL;
}

template <class DataType>  
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
	Node<DataType> *r, *s;
	first = new Node<DataType>;                 
	r = first;                          
	for (int i = 0; i < n; i++)
	{ 
		s = new Node<DataType>;
		s -> data = a[i];       
		r -> next = s;
		s -> prior = r;
		r = s;        
	}
	r -> next = NULL; 
	first -> prior = r;
}

template <class DataType>
LinkList<DataType> :: ~LinkList( )
{
	Node<DataType> *q;
	while (first != NULL)       
	{
		q = first;                 
		first = first->next;        
		delete q;    
	}
}

template <class DataType> 
int LinkList<DataType> ::Length( )
{
	Node<DataType> *p = first -> next;  
	int l=0;
	while(p!=NULL)
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
	Node<DataType> *p = first, *s;
	int count = 0;         
	while (count != i-1)  
	{
		p = p -> next;
		count++;
	}
	if (i == Length()+1)
	{
		s=new Node<DataType>;
		s -> data = x;
		p -> next = s;
		s -> prior = p;
		s -> next = NULL;
	}
	else
	{
		s=new Node<DataType>;
		s -> data = x;
		s -> prior = p;
		s -> next = p -> next;
		p -> next -> prior = s;
		p -> next = s;
	}
}

template <class DataType>  
void LinkList<DataType> :: Delete(int i)
{
	if (i > Length()) throw i;
	Node<DataType> *p = first,*s, *d;
	int count = 0; 
	while (count != i - 1)  
	{
		p = p -> next;
		count++;
	}
	d = p -> next;  
	p -> next = d -> next;
	d -> next -> prior = p;       
	delete d; 
}

template <class DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
	Node<DataType> *p = first -> next;
	int count = 1;        
	while (p != NULL) 
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
	Node<DataType> *p = first -> next;
	while (p != NULL)
	{
		cout <<p->data<<"  ";
		p = p -> next;                
	}
	cout<<endl;
}

