#include <iostream>
#include "LinkList.h"
using namespace std;

template <class DataType>
LinkList<DataType> :: LinkList( )
{
	first = NULL;      
}

template <class DataType>  
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
	Node<DataType> *r, *s;
	first = new Node<DataType>;
	first->data =a[0];             
	r = first;  
	for (int i = 1; i < n; i++)
	{ 
		s = new Node<DataType>; 
		s->data = a[i];        
		r->next = s; 
		r = s;                
	}
	r->next = NULL;  
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
LinkList<DataType>::LinkList(LinkList<DataType> &L)    
{   
    Node<DataType> *s,*srcptr=L.first;              
	Node<DataType>  *destptr=first=new Node<DataType>;
	while (srcptr->next!=NULL)
	{    
		  s=new Node<DataType>;       
		  s->data=srcptr->next->data;
          destptr->next=s;
		  destptr=destptr->next;
		  srcptr=srcptr->next;
	 }
     destptr->next=NULL; 
    Node<DataType> *tt=first;
	first=first->next;
	delete tt; 
}
 
template <class DataType>
LinkList<DataType>& LinkList<DataType>::operator=(LinkList<DataType> &L)    
{   
	Node<DataType> *s,*srcptr=L.first;              
	Node<DataType>  *destptr=first=new Node<DataType>;
	while (srcptr->next!=NULL)
	{     
		s=new Node<DataType>;        
		s->data=srcptr->next->data;
        destptr->next=s;
		destptr=destptr->next;
		srcptr=srcptr->next; 
	}
 	destptr->next=NULL;
    Node<DataType> *tt=first;
	first=first->next;
	delete tt; 	
    return *this;  
}

template <class DataType>  
void LinkList<DataType> :: Insert(int i, DataType x)
{ 
	if(i==1)
	{
		Node<DataType> *p,*s;
		s = new Node<DataType>;  
		s->data = x; 
		s->next = first->next;
		first = s;	
	}
	else
	{
		Node<DataType> *p = first, *s;
		int count = 1;               
	    while (p != NULL && count < i - 1) 
	    {
			p = p->next;                  
			count++;
	    }
	    if (p == NULL) throw i;     
	    else 
		{
			s = new Node<DataType>;  
			s->data = x;     
			s->next = p->next; 
			p->next = s;   
	    }			
	}	
}
template <class DataType>  
void LinkList<DataType> :: Insert(DataType x)
{
	Node<DataType> *p = first,*s;
	while(p!=NULL)
	{
		if(p->next==NULL)
		{
			s=new Node<DataType> ;
			s->data=x;
			s->next=NULL;
			p->next=s;
			return ;
		} 		
		if((p->data<=x)&&(p->next->data>x))
		{
			s=new Node<DataType> ;
			s->data=x;
			s->next=p->next;
			p->next=s;			
			return ;
		}
		p=p->next;
	}
}

template <class DataType>  
DataType LinkList<DataType> :: Delete(int i)
{
	Node<DataType> *p, *q;
	DataType x;
	if(i==1)
	{
		p=first;
		first=first->next;
		x=p->data;
		delete p;
		return x;
	}
	else
	{
		int count = 1;
		p = first;               
		while (p != NULL && count < i - 1)  
		{
			p = p->next;
			count++;
		}
		if (p == NULL || p->next == NULL)  
			throw i; 
		else 
		{
			q = p->next; x = q->data;        
			p->next = q->next;              
			delete q; 
			return x;
		}			
	}
}

template <class DataType>  
void LinkList<DataType> :: Purge()
{
	Node<DataType> *p = first,*q,*s,*before;
	while(p!=NULL)
	{
		q=p->next;
		before=p;
		while(q!=NULL)
		{
			if(q->data==p->data)
			{
				s=q->next;
				before->next=s;
				delete q;
				q=s;
				continue;	
			}
			before=q;
			q=q->next;
		}
		p=p->next;
	}
}
template <class DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
	Node<DataType> *p = first;
	int count = 1;        
	while (p != NULL)    
	{
		if (p->data == x) return count;     
		p = p->next;                   
		count++;
	}
	return 0;                        
}

template <class DataType>
void LinkList<DataType> :: PrintList( )
{
	Node<DataType> *p = first;               
	while (p != NULL)
	{
		cout << p->data<<"  ";
		p = p->next;                
	}
	cout<<endl;
}

//Addtional functions:
template <class DataType> 
int LinkList<DataType> ::Length( )
{
	Node<DataType> *p = first;  
	int l=0;
	while(p!=NULL)
	{
		l++;
		p=p->next;
	}
	return l;
}

template <class DataType> 
Node<DataType> *  LinkList<DataType> ::getfirst()
{    return   first; 
}

template <class DataType>  
int LinkList<DataType> :: Increase( ) 
{
	Node<DataType> *q, *p = first;
	while (p->next != NULL)    
	{   q=p->next;
	    if(p->data<q->data)  p=q;
	    else return 0;
	}
	return 1;                        
}

template <class DataType>
void LinkList<DataType> ::Reverse()
{
	Node<DataType> *p = first; 
	Node<DataType> *before=NULL,*tnext;
		             
	while (p != NULL)
	{
		tnext=p->next;
		p->next=before;
		before=p;
		p =tnext;                 
	}
	first=before;
}