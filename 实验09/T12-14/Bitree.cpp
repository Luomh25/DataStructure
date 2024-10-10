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

BiNode *Bitree::getRoot()
{
	return root;
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
	if(bt == NULL)  return;
	else
	{		
		cout<<bt -> data<<" ";
        PreOrder(bt -> lchild);
		PreOrder(bt -> rchild);
	}
}

void Bitree::InOrder(BiNode *bt)
{
	if (bt == NULL)  return;
    else 
	{
        InOrder(bt -> lchild);
        cout<<bt -> data<<" ";
        InOrder(bt -> rchild);
	}
}

void Bitree::PostOrder(BiNode *bt)
{
	if (bt == NULL)  return;
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
	if (root==NULL) return;
	else 
	{
		Q[++rear]=root;
		while (front != rear)
		{
			q = Q[++front];
     		cout<<q -> data<<" "; 		
    		if (q -> lchild != NULL) 
				Q[++rear]=q -> lchild;		
			if (q -> rchild != NULL) 
				Q[++rear] = q -> rchild;
		}
	}
}

BiNode *CopyTree(BiNode *root)
{
	if(root==NULL) return NULL;
	else
	{
		BiNode *newltre,*newrtre,*newnode;
		newltre=CopyTree(root->lchild);
		newrtre=CopyTree(root->rchild);
		newnode=new BiNode;
		newnode->data=root->data;
		newnode->lchild=newltre;
		newnode->rchild=newrtre;
		return newnode;
	}
}

void Parent(BiNode * root, char x, BiNode * &p)
{
    if (root != NULL)
    {
        if (root->data == x)  p = NULL;
        else
        {
            p = root;
            Parent(root -> lchild, x, p);
			if(p == NULL)  // 左子树没有找到
            {
				Parent(root -> rchild, x, p);
			}
        }
    }
}

void Bitree::info(BiNode *bt)
{
	if (bt)  cout<<"该节点: "<<bt -> data;
	else  cout<<"空节点 ";
}

void Bitree::del(char x)
{
	BiNode* p = NULL;
	Delete(root, x, p);
}

void Bitree::Delete(BiNode *bt, char x, BiNode *&p)
{
    if (bt != NULL)
    {
        if (bt->data == x)
        {
            if (p == NULL)  bt = NULL;
            else if (p->lchild == bt)  p->lchild = NULL;
            else  p->rchild = NULL;
        }
        else
        {
            p = bt;
            Delete(bt->lchild, x, p);
            Delete(bt->rchild, x, p);
        }
    }
}

void Exchange(BiNode * root)
{
    if (root != NULL)
    {
        Exchange(root->lchild);
        Exchange(root->rchild);
		BiNode * temp = NULL;
        temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;    
    }
}