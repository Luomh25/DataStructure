#include <iostream>
#include "LinkList.h"
using namespace std;
template <class DataType>
LinkList<DataType> :: LinkList( )
{
	first = NULL;  
}

template <class DataType>  
LinkList<DataType> :: LinkList(int a[],int n)
{
	if(n==0)
	{
		first=NULL;
	}
	else
	{
		Node<DataType> *r, *s;
		first = new Node<DataType>;
		first->data =a[0];             
		r = first;  
		first->next = NULL; 
		for (int i = 1; i < n; i++)
		{ 
			s = new Node<DataType>; 
			s->data = a[i];        
			r->next = s; 
			r = s;                
		}
		r->next = NULL;  		
	}	
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
void LinkList<DataType> :: Delete(DataType x)
{
	Node<DataType> *p, *q,*before;
	if(first->data==x)
	{
		q=first;
		first=first->next;
		delete q;
		return ;
	} 
	before=first;
	p=first->next;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			before->next=p->next;
			delete p;
			return ;				
		}
		before=p;
		p=p->next;
	}
}

template <class DataType>  
void LinkList<DataType> :: PrintList()
{
	Node<DataType> *q=first;
	if(q==NULL)
	{
		cout<<"empty set"<<endl;
		return ;
	}
	while (q != NULL)        
	{
		cout<<q->data<<" ";          
		q=q->next;  
	}	
	cout<<endl;
}

template <class DataType>  
int LinkList<DataType> :: Locate(DataType x)
{
	Node<DataType> *q=first;
	while (q!= NULL)        
	{
		if(q->data==x)
			return 1;        
		q=q->next;  
	}	
	return 0;
} 

template <class DataType>  
void LinkList<DataType> :: Insert(DataType x)
{
	Node<DataType> *s= new Node<DataType>;
	s->data=x;
	s->next=first;
	first=s;
} 

template <class DataType> 
int LinkList<DataType> ::Length( )
{
	Node<DataType> *p = first->next;  
	int l=0;
	while(p!=NULL)
	{
		l++;
		p=p->next;
	}
	return l;
}

template <class T> 
int IsEqual(LinkList<T> &A, LinkList<T> &B)
{
	Node<T> *q=B.first;
	while (q != NULL)        
	{
		if(A.Locate(q->data)==0)
			return 0;
		q=q->next;
	}
	q=A.first;
	while (q != NULL)        
	{
		if(B.Locate(q->data)==0)
			return 0;
		q=q->next;
	}
	return 1;
}

template <class T> 
void Interest(LinkList<T> &A, LinkList<T> &B)
{
	Node<T> *q=B.first,*tp;
	while (q != NULL)        
	{
		if(A.Locate(q->data)==0)
		{
			tp=q->next;
			B.Delete(q->data);
			q=tp;	
			continue;
		}	
		q=q->next;
	}
}

template <typename T> 
void unionList(LinkList<T> &A, LinkList<T> &B)
{
	Node<T> *q=B.first;
	while (q != NULL)        
	{
		if(A.Locate(q->data)==0)
		{
			A.Insert(q->data);
		}	
		q=q->next;
	}
}

template <typename T> 
void Difference(LinkList<T> &A, LinkList<T> &B)
{
	Node<T> *q=A.first,*tp;
	while (q != NULL)        
	{
		if(B.Locate(q->data)==1)
		{
			tp=q->next;
			A.Delete(q->data);
			q=tp;	
			continue;
		}	
		q=q->next;
	}
}
