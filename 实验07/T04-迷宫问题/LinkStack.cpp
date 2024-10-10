#include <iostream>
using namespace std;
#include "LinkStack.h"

LinkStack::LinkStack( )
{
	top=NULL;
}

LinkStack :: ~LinkStack( )
{   
	Node *q;
	while (top != NULL)       
	{	
		q = top;                 
		top = top->next;     
		delete q;    
	}
}
 
void LinkStack::Push(int x,int y,int d)
{
	Node *s;
	s = new Node; 
	s -> p.x = x;
	s -> p.y = y;
	s -> p.d=d;      
	s -> next=top;
	top=s;
}

Point LinkStack::Pop( )
{ 
    Point x;   
	Node *tp;
    if (top==NULL) throw "ÏÂÒç";
    x = top -> p; 
	tp = top;
    top = top -> next;
    delete tp;
    return x;
}

Point LinkStack::GetTop( )
{
	if (top != NULL)  return top -> p;
    else throw "¿Õ"; 
}

int LinkStack::Empty( )
{
	if(top == NULL) return 1;
	else return 0;
}