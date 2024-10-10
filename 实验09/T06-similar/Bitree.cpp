#include <iostream>
using namespace std;
#include "Bitree.h"
Bitree::Bitree()
{
	root = Creat(root);
}

Bitree::Bitree(BiNode *bt)
{
	root = bt;
}

Bitree::~Bitree()
{
	Release(root);
}

void Bitree::isEmpty()
{
    if (root == NULL)
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
}

BiNode *Bitree::getRoot()
{
	return root;
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
    if (ch=='#')  return NULL;
    else
	{ 
	    bt = new BiNode;
        bt -> data=ch;
        bt -> lchild = Creat(bt -> lchild);
        bt -> rchild = Creat(bt -> rchild);
    } 
    return bt;
}     
void Bitree::Release(BiNode *bt)
{
	if (bt != NULL)
	{                  
	    Release(bt -> lchild);   //释放左子树
        Release(bt -> rchild);   //释放右子树
        delete bt;
	}  

}

void Bitree::PreOrder(BiNode *bt)
{
	if(bt==NULL)  return;
	else
    {		
		cout<<bt -> data<<" ";
        PreOrder(bt -> lchild);
		PreOrder(bt -> rchild);
	}
}

void Bitree::InOrder(BiNode *bt)
{
	if (bt==NULL)  return;
    else
    {	
        InOrder(bt -> lchild);
        cout<<bt -> data<<" ";
        InOrder(bt -> rchild);
	}
}

void Bitree::PostOrder(BiNode *bt)
{
	if (bt==NULL)  return;
    else
    {	
        PostOrder(bt -> lchild);
        PostOrder(bt -> rchild);
        cout<<bt -> data<<" ";
	}
}

void Bitree::LeverOrder( )
{
	int front = -1, rear = -1;
	BiNode *Q[MaxSize], *q;
	if (root == NULL) return;
	else 
	{
		Q[++rear] = root;
		while (front != rear)
		{
			q=Q[++front];
     		cout<<q -> data<<" "; 		
    		if (q -> lchild != NULL) 
				Q[++rear] = q -> lchild;		
			if (q -> rchild != NULL) 
				Q[++rear] = q -> rchild;
		}
	}
}

int Like(BiNode * s, BiNode * t)
{
	if (s == NULL && t == NULL)  return 1;
	else if ((s == NULL && t != NULL)||(s != NULL && t == NULL))
		return 0;
	else
	{
		int same = Like(s -> lchild, t -> rchild);
		if(same)  same = Like(s -> rchild, t -> rchild);
		return same;
	}
}