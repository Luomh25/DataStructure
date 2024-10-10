#include <iostream>
#include <cmath>
using namespace std;
#include "LinkList.h"

LinkList::LinkList()
{ 
	first = new Node;
	first -> next = NULL;
}

LinkList::LinkList(double a[],int b[],int n)
{
	Node *r,*s;
	first = new Node;
	r = first;
	for(int i = 0;i < n;i++)
	{ 
		s = new Node;
	  	s -> coef = a[i];
		s -> exp = b[i];
	  	r -> next = s;
		r = s; 
	}
	r -> next = NULL; 
}

LinkList::~LinkList()
{
	Node *q;
	while(first != NULL)
	{
		q = first;
		first = first -> next;
		delete q;
	}
}

void LinkList:: PrintList()
{   
	Node *p = first -> next;
	if (p == NULL)
	{
		cout<<"0"<<endl;
		return;
	}
	while (p != NULL)
	{
		if (p -> coef > 0 && p != first -> next)
		{
			cout<<"+";
		}
		if (p -> coef == 1 && p -> exp != 0)
		{
			;
		}
		else if (p -> coef == -1)
		{
			if(p -> exp == 0) cout<<"-1";
			else cout<<"-";
		}
		else cout<<p -> coef;
		if(p -> exp > 0) cout<<"x";
		if(p -> exp > 1) cout<<"^"<<p -> exp;
		p = p -> next;
	}
	cout<<endl;
}

void Add(LinkList &A,LinkList &B)
{
	Node *pre = A.first,*p = pre->next;
	Node *qre = B.first,*q = qre->next;
	while (p != NULL && q != NULL)
	{
		if (p -> exp < q -> exp)
		{
			pre = p;
			p = p -> next;
		}
		else if (p -> exp > q -> exp)
		{
			Node *v = q -> next;
			pre -> next = q;
			q -> next = p;
			q = v;
		}
		else
		{
			p -> coef = p -> coef + q -> coef;
			if (p -> coef == 0)
			{
				pre -> next = p -> next;
				delete p;
				p = pre -> next;
			}
			else
			{
				pre = p;
				p = p -> next;
			}
			qre -> next = q -> next;
			delete q;
			q = qre -> next;
		}
	}
	if(q != NULL) pre -> next = q;
	delete B.first;
}
