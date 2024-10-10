#include <iostream>
#include "LinkList.h"
using namespace std;

LinkList::LinkList()
{
	first = new Node;
	first -> next = NULL;
}

LinkList::LinkList(int a[], int n)
{
	Node * r, * s;
	first = new Node;                 
	r = first;                          
	for (int i = 0; i < n; i++)
	{ 
		s = new Node;
		s -> data = a[i];       
		r -> next = s;
		r = s;        
	}
	r -> next = NULL; 
}

LinkList::~LinkList()
{
	Node * q = NULL;
	while (first != NULL)       
	{
		q = first;                 
		first = first -> next;        
		delete q;    
	}
}

void LinkList::PrintList()
{
	Node * p = first -> next;
	while (p != NULL)
	{
		cout<<p -> data<<" ";
		p = p -> next;                
	}
	cout<<endl;
}

Node * LinkList::getfirst()
{
	return first;
}

void StraightSort(LinkList &A)
{
	Node* pre = A.first, * p = A.first->next, *q = p->next,*u;
	while (q != NULL)
	{
		while (q != p)
		{
			while (p->data < q->data)
			{
				pre = p;
				p = p->next;
			}
			if (p != q)
			{
				u = q->next;
				pre->next = q;
				q->next = p;
				q = u;
			}
			else q = p->next;
		}
		pre = A.first;
		p = A.first->next;
	}
}

void SelectSort(LinkList& A)
{
	Node*p = A.first->next,*s,*q;
	int exchange;
	while (p != NULL)
	{
		s = p;
		q = p->next;
		while (q != NULL)
		{
			if (q->data < s->data)s = q;
			q = q->next;
		}
		if (p != s)
		{
			exchange = p->data;
			p->data = q->data;
			q->data = exchange;
		}
		p = p->next;
	}
}