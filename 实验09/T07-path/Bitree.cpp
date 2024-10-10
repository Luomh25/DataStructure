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

BiNode *Bitree::getleftleaf(BiNode * root)
{
	int max_dpt = 1;
	BiNode * res = root;
	helper(root, 1, max_dpt, res);
	return res;
	
}

void Bitree::helper(BiNode *node, int dpt, int &max_dpt, BiNode *&res)
{
	if (!node)  return;
	if (dpt > max_dpt)
	{
		max_dpt = dpt;
		res = node;
	}
	helper(node->lchild, dpt+1, max_dpt, res);
	helper(node->rchild, dpt+1, max_dpt, res);
	
}

void Path(BiNode * root, BiNode * p)
{
    BiNode * stack[MaxSize] = {NULL};
    int tag[MaxSize] = {0};
    int top = -1;
    BiNode * T = root;
    while (T != NULL || top != -1)
    {
        while (T != NULL)
        {
            top++;
            stack[top] = T;
            tag[top] = 0;
            T = T->lchild;
        }
        while (top != -1 && tag[top] == 1)
        {
            T = stack[top];
            if (T == p)
            {
                for (int i = 0; i < top; i++)
                {
                    cout<<stack[i]->data;
                    if (i == top - 1)
                    {
						cout<<p->data;
                        return;
                    }
                }
                break;
            }
            else  top--;
        }
        if (top != -1)
        {
            T = stack[top]->rchild;
            tag[top] = 1;
        }
        else  return;
    }
}