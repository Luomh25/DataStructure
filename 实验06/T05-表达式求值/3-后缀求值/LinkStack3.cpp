#include <iostream>
using namespace std;
#include "LinkStack3.h"

LinkStack::LinkStack()  {top=NULL;}

LinkStack::~LinkStack()
{
	Node *q;
	while (top != NULL)        
	{
		q = top;                 
		top = top->next;    
		delete q;    
	}
}

void LinkStack::Push(char x)
{
	Node *s=new Node;s->data=x;
	s->next=top;top=s;
}

char LinkStack::Pop()
{
	char x;
	Node *p;
	if(top==NULL) cout<<"下溢"<<endl;
	x=top->data ;p=top;
	top=top->next ;
	delete p;
	return x;
}

char LinkStack::GetTop()
{
	if(top!=NULL) return top->data ;
}

int Operate(char a,char thera,char b)
{
	int c;
	int m,n;
	m=a-48;n=b-48;
	switch(thera){
	case '+':c=m+n;break;
	case '-':c=m-n;break;
	case '*':c=m*n;break;
	case '/':c=m/n;break;
	}
	return (c+48);
}

char Sufix()//算术表达式求值的算符优先算法。
{//设OPTR和OPND分别为运算符栈和运算数栈。OP为运算符集合。   
   LinkStack S;
   S.Push('#');
   char c=getchar();
   while (c !='#')
   {
    	if('1'<=c && c<='9' ) //运算数 
        {
			S.Push(c);
			c=getchar();
		} 
        else 
		{
            char b=S.Pop();
            char a=S.Pop();
            char v=Operate(a,c,b);
            S.Push(v);
            c=getchar();
        }
    }//while
    return S.GetTop();
} //Sufix