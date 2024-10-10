#include <iostream>
using namespace std;
#include "LinkStack2.h"
const int MaxSize = 100;

template <typename T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template <typename T>
LinkStack<T>::~LinkStack()
{
	Node<T> *p;
	while (top != NULL)
	{
		p = top; //暂存栈顶地址
 		top = top->next;
 		delete p;
 	}
}

template <typename T>
void LinkStack<T>::Push(T x)
{
	Node<T> *s = new Node<T>;
 	s->data = x;
 	s->next = top;
 	top = s;
}

template <typename T>
T LinkStack<T>::Pop()
{
	if (top == NULL) throw"栈空";
 	T temp = top->data;
 	Node<T> *p = top; //暂存栈顶
 	top = top->next;
 	delete p;
 	return temp;
}

template <typename T>
T LinkStack<T>::GetTop()
{
	if (top == NULL) throw"栈空";
 	return top->data;
}

template <typename T>
int LinkStack<T>::Empty()
{
	if (top == NULL)return 1;
 	else return 0;
}

template <typename T>
void LinkStack<T>::makeEmpty()
{
	top = -1;
}

int icp(const char a)//栈外优先级 
{
	switch(a)
	{
		case '#':return 0;
		case '(':return 6;
		case '+':return 2;
		case '-':return 2;
		case '*':return 4;
		case '/':return 4;
		case '%':return 4;
		case ')':return 1;
		default:throw "ERROR!";
	}
}

int isp(const char a)//栈内优先级 
{
	switch(a)
	{
		case '#':return 0;
		case '(':return 1;
		case '+':return 3;
		case '-':return 3;
		case '*':return 5;
		case '/':return 5;
		case '%':return 5;
		case ')':return 6;
		default:throw "ERROR!";
	}
}

void Run()
{
	char Inf[MaxSize],ch;
	LinkStack<char> OPTR;
	OPTR.Push('#');
	cout<<"请输入需要转换的中缀表达式："<<endl;
	cin>>Inf;
	int count = 0;
	ch = Inf[0];
	try
	{
		while(ch != '#' || OPTR.GetTop() != '#')
		{
			if(ch >= '0' && ch <= '9')
			{
				cout<<ch;
				ch = Inf[++count];
				if(ch=='\0') ch='#';
			}
			else if(icp(ch)>isp(OPTR.GetTop()))
			{
				OPTR.Push(ch);
				ch=Inf[++count];
				if(ch=='\0') ch='#';
			}
			else if (icp(ch) < isp(OPTR.GetTop()))
			{
				cout << OPTR.Pop();
			}
			else if (ch == ')')
			{
				OPTR.Pop();
				ch=Inf[++count];
				if(ch=='\0') ch='#';
			}
		}
		cout<<endl;
	}
	catch (const char *s)
	{
		cout<<s<<endl;
	}
}
