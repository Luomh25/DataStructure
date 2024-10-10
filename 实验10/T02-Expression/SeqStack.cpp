#include <iostream>
#include <cstring> 
#include "SeqStack.h"
using namespace std;

template<class T>
SeqStack<T>::SeqStack()
{
    top = -1;
}

template<class T>
SeqStack<T>::~SeqStack()
{
    //nothing
}

template <class T> 
void SeqStack<T>::Push(T x)//get in 
{
    if (top==StackSize-1)  throw "上溢";
    top++;
    data[top]=x;
}

template <class T>
T SeqStack<T>::Pop( )
{ 
    T x;
    if (top==-1)  throw "下溢";
    x=data[top--];
    return x;
}

template <class T> 
T SeqStack<T>::GetTop( )
{
	if (top!=-1)  return data[top];
    return 0;   
}

int inp(char c)
{

  	if(c=='#') return 0;
	if(c=='(') return 1;
	if(c=='*'||c=='/'||c=='%')  return 5;  
	if(c=='+'||c=='-') return 3;   
	if(c==')') return 6;
	return 0;   
}

int exp(char c)
{
  	if(c=='#') return 0;
	if(c=='(') return 6;
	if(c=='*'||c=='/'||c=='%')  return 4;  
	if(c=='+'||c=='-') return 2;   
	if(c==')') return 1;  
	return 0;    
}

template <class T> 
int SeqStack<T>::Empty( )
{
	if(top==-1)  return 1;
	else  return 0;
}

void postfix(string &s,SeqStack<int> &num,SeqStack<char> &sign,string &posts,int &lp)
{
	sign.Push('#');
	int l=s.length();
	int k=-1;
	for(int i=0;i<l;i++)
	{
		char c=s[i]; 
		if(c >= 'A' && c <= 'Z')
		{
			cout<<c; 
			k++;
			posts[k]=c;
		}
		else 
		{
			char top=sign.GetTop( ); 
			if(exp(c) > inp(top))  sign.Push(c);
			else if(exp(c) < inp(top))
			{
				while(exp(c) < inp(top))
				{				
					cout<<sign.GetTop();
					k++;
					posts[k] = sign.GetTop();	 
					sign.Pop();
					top = sign.GetTop( );
				}
				if(exp(c) > inp(top))  sign.Push(c);
				else if((exp(c) == inp(top)) && c == ')')  sign.Pop();					
			}
			else if((exp(c)==inp(top))&& c==')')  sign.Pop();
		}
	}
	cout<<endl;
	lp=k;
}

Bitree::Bitree()
{
    root = NULL;
}

/*Bitree::Bitree(BiNode *bt)
{
	root = bt;
}*/

Bitree::Bitree(char post[],int lp)
{
	SeqStack<BiNode *> s;
	for(int i=0;i<=lp;i++)
	{
		char c = post[i];
		if(c >= 'A' && c <= 'Z')
		{	
			BiNode *bt = new BiNode;
			bt -> data = c;
			bt -> lchild = NULL;
			bt -> rchild = NULL; 
			s.Push(bt);
		}
		else
		{
			BiNode *bt = new BiNode;
			bt -> data = c;
			bt -> rchild = s.Pop();
			bt -> lchild = s.Pop();
			s.Push(bt);
		}
	}
	root=s.Pop();
}

Bitree::~Bitree()
{
    Release(root);
}

void Bitree::PreOrder()
{
    PreOrder(root);
}

void Bitree::InOrder()
{
    InOrder(root);
}

void Bitree::PostOrder()
{
    PostOrder(root);
}

BiNode *Bitree::Creat(BiNode *bt)
{
	char ch;
	cout<<"请输入创建一棵二叉树的结点数据"<<endl;
	cin>>ch;
	if(ch == '#')  return NULL;
	else
	{
		bt = new BiNode;
		bt -> data = ch;
		bt -> lchild = Creat(bt -> lchild);
		bt -> rchild = Creat(bt -> rchild);	
		return bt;
	}
}

void Bitree::Release(BiNode *bt)
{
    if (bt != NULL)
    {
        Release(bt -> lchild);
        Release(bt -> rchild);
        delete bt;
    }
}

void Bitree::PreOrder(BiNode *bt)
{
    if(bt == NULL) return;
    else
    {
        cout<<bt->data<<" ";
        PreOrder(bt -> lchild);
        PreOrder(bt -> rchild);
    }
}

void Bitree::InOrder(BiNode *bt)
{
    if (bt==NULL)  
	{
		return;
	}        
    else {	
        InOrder(bt->lchild);
        cout<<bt->data<<" ";
        InOrder(bt->rchild);
	}
}

void Bitree::PostOrder(BiNode *bt)
{
	if (bt == NULL)  return;
    else
    {	
        PostOrder(bt -> lchild);
        PostOrder(bt -> rchild);
        cout<<bt->data<<" ";
	}
}