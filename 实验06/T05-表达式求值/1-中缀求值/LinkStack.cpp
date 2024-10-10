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
	while (top != NULL)        	 //�ͷŵ������ÿһ�����Ĵ洢�ռ�
	{	
		q = top;                 //�ݴ汻�ͷŽ��
		top = top -> next;       //firstָ���ͷŽ�����һ�����
		delete q;
	}
}

void LinkStack::Push(char x)
{
	Node *s;
	s = new Node;     //ֱ���Լ��׳��쳣 
	if(s == NULL) throw "����"; 
	s -> data = x;              //����һ��������Ϊx�Ľ��
	s -> next = top; 
	top = s;                    //�����ŵ�ջ�� 
}

char LinkStack::Pop()
{
    Node *p;
    if (top == NULL) throw "����";
    char x = top -> data; 
	p = top;
    top = top -> next;			//topָ���ƶ� 
    delete p;
    return x;
}

char LinkStack::GetTop()
{
    if (top != NULL)  
    	return top -> data;
    else
		throw "��"; 
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

char com()//�������ʽ��ֵ����������㷨��
{//��OPTR��OPND�ֱ�Ϊ�����ջ��������ջ��OPΪ��������ϡ�   
    LinkStack(OPTR);
    OPTR.Push('#');
    LinkStack(OPND); 
    char c=getchar();
    while (c != '#')
    {
        if('1'<=c && c<='9' ) //������������ջ
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
                case '<'://ջ��Ԫ������Ȩ��,�������ջ 
                    OPTR.Push(c); 
                    c=getchar(); 
                    break;
                case '=':
                    //cout<<222<<endl;//�����Ų�������һ�ַ� 
                    OPTR.Push(c);
                    c=getchar();
                    break;
                case '>':  //��ջ������������ջ
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
