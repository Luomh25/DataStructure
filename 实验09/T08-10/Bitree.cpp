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

int Bitree::countLeaves()
{
	int num = 0; 
	if (root == NULL) return 0;
	else if (root != NULL)
	{
		countLeaves(root, num);
	}
	else
		num++;
	return num;
}

void Bitree::countLeaves(BiNode* root, int &num)  // 用引用的形式参数传递
{
    //前置条件： root 不是空指针
	if (root->lchild == NULL && root->rchild == NULL)
	{
		num++;
	}
	else
	{
		if(root -> lchild != NULL)
		{
			countLeaves(root -> lchild, num);
		}
		if (root -> rchild != NULL)
		{
			countLeaves(root -> rchild, num);
		}
	}
}

void leavesPrint(BiNode * root)
{
	if (root != NULL)
	{
		if (!root->lchild && !root->rchild)
		{
			cout<<root->data;
		}
		leavesPrint(root -> lchild);
		leavesPrint(root -> rchild);
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

int Bitree::countNode()
{
	int num = 0;
	countNode(root, num);
	return num; 
}

void Bitree::countNode(BiNode *root, int &num)
{
	if (root)
	{
		num++;
		countNode(root->lchild, num);
		countNode(root->rchild, num);
	}
}

int max(int a, int b)
{
    if (a > b)  return a;
    else return b;
}

int Depth(BiNode * root)
{
    if (root == NULL)  return 0;
    else
    {
        int hl = Depth(root->lchild);
        int hr = Depth(root->rchild);
        return max(hl, hr) + 1;
    }
}