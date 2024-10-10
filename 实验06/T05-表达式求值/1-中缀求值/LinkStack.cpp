#include<iostream>
using namespace std;
#include "LinkStack.h" 

LinkStack::LinkStack()
{
    top = NULL;
}

LinkStack::~LinkStack()
{   
	Node *q;
	while (top != NULL)        	 //释放单链表的每一个结点的存储空间
	{	
		q = top;                 //暂存被释放结点
		top = top -> next;       //first指向被释放结点的下一个结点
		delete q;
	}
}

void LinkStack::Push(char x)
{
	Node *s;
	s = new Node;     //直接自己抛出异常 
	if(s == NULL) throw "上溢"; 
	s -> data = x;              //申请一个数据域为x的结点
	s -> next = top; 
	top = s;                    //将结点放到栈顶 
}

char LinkStack::Pop()
{
    Node *p;
    if (top == NULL) throw "下溢";
    char x = top -> data; 
	p = top;
    top = top -> next;			//top指针移动 
    delete p;
    return x;
}

char LinkStack::GetTop()
{
    if (top != NULL)  
    	return top -> data;
    else
		throw "空"; 
}

int LinkStack::Empty()
{
    if (top == NULL) return 1;
    else return 0;
}

bool InOP(char c)
{
	bool x=0;
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')') x=1;
	return x;
}

int getpriority(char a)
{
	int p=0;
	switch(a){
		case '+':p=1;break;
		case '-':p=1;break;
		case '*':p=3;break;
		case '/':p=3;break;
	}
	return p;
}

char Preceded(char a,char b)
{
	if(b=='(') return '<';
	if(b==')')
	{
		if(a=='(') return '=';
		else return '>';
	}
	int m,n;
	m=getpriority(a);
	n=getpriority(b);
	if(m>n) return '>';
	else if(m<n) return '<';
	else return '=';
}

int Operate(char a,char thera,char b)
{
	int c;
	int m,n;
	m=a-48;
    n=b-48;
	switch(thera)
	{
		case '+':c=m+n;break;
		case '-':c=m-n;break;
		case '*':c=(a-48)*(b-48);break;
		case '/':c=(a-48)/(b-48);break;
	}
	return c;
}

char com()//算术表达式求值的算符优先算法。
{//设OPTR和OPND分别为运算符栈和运算数栈。OP为运算符集合。   
    LinkStack(OPTR);
    OPTR.Push('#');
    LinkStack(OPND); 
    char c=getchar();
    while (c != '#')
    {
        if('1'<=c && c<='9' ) //不是运算符则进栈
        {
            OPND.Push(c);
            c=getchar();
        } 
		else if(c=='(') 
        {
            OPTR.Push(c);
            c=getchar();
        }
		else if(c==')')
        {
			while( OPTR.GetTop() !='(')
            {
				char thera=OPTR.Pop();
                char b=OPND.Pop();
                char a=OPND.Pop();
                char v=('0'+ Operate(a,thera,b));
                OPND.Push(v);
			}
			OPTR.Pop();
			c=getchar();
		}
        else 
        {
			switch (Preceded(OPTR.GetTop(),c)) 
            {
                case '<'://栈顶元素优先权低,运算符入栈 
                    OPTR.Push(c); 
                    c=getchar(); 
                    break;
                case '=':
                    //cout<<222<<endl;//脱括号并接收下一字符 
                    OPTR.Push(c);
                    c=getchar();
                    break;
                case '>':  //退栈并将运算结果入栈
                    char thera=OPTR.Pop();
                    char b=OPND.Pop();
                    char a=OPND.Pop();
                    char v=Operate(a,thera,b);
                    OPND.Push(v);
                    break;
            } //switch
        }
    }//while
    while(OPTR.GetTop()!='#')
    {
        char thera=OPTR.Pop();
        char b=OPND.Pop(); 
        char a=OPND.Pop();
        char v=('0'+ Operate(a,thera,b));
        OPND.Push(v);
	}
    return OPND.GetTop();
}
