#include <iostream>
using namespace std;
#include "Bitree.h"

Bitree::Bitree()
{
    root = Creat(root);
}

Bitree::~Bitree()
{
    Release(root);
}

void Bitree::PreOrder()
{
    PreOrder(root);
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
    if (ch == '#')
    {
        return NULL;
    }
    else
    {
        bt = new BiNode;
        bt -> data = ch;
        bt -> lchild = Creat(bt -> lchild);
        bt -> rchild = Creat(bt -> rchild);
    }
    return bt;
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

void Bitree::LeverOrder()
{
    int front = -1,rear = -1;
    BiNode *Q[MaxSize],*q;
    if (root == NULL) return;
    else
    {
        Q[++rear] = root;
        while (front != rear)
        {
            q = Q[++front];
            cout<<q->data<<" ";
            if (q->lchild!=NULL) Q[++rear]=q->lchild;
            if (q->rchild!=NULL) Q[++rear]=q->rchild;
        }
    }
}

BiNode *Bitree::getRoot()
{
    return root;
}
        
void Bitree::PreOrder(BiNode *bt)
{
    int top = -1;
    BiNode *s[MaxSize] = {NULL};
    while (bt != NULL || top != -1)
    {
        while (bt != NULL)
        {
            cout<<bt -> data;
            s[++top] = bt;
            bt = bt -> lchild;
        }
        if (top != -1)
        {
            bt = s[top--];
            bt = bt -> rchild;
        }
    }
}

void Bitree::InOrder(BiNode *bt)
{
	int top = -1;
	BiNode *s[MaxSize] = {NULL};
	while (bt != NULL || top != -1)
	{
		while (bt != NULL)
		{
			s[++top] = bt;
			bt = bt->lchild;
		}
		if (top != -1)
		{
			bt = s[top--];
			cout<<bt -> data;
			bt = bt -> rchild;
		}	
	}
}

void Bitree::PostOrder(BiNode *bt)
{
    int top = -1;
    element s[MaxSize] = {NULL,1};
    while (bt != NULL || top != -1)
    {
        while (bt != NULL)
        {
            top++;
            s[top].ptr = bt;
            s[top].flag = 1;
            bt = bt -> lchild;
        }
        while (top != -1 && s[top].flag == 1)
        {
            bt = s[top--].ptr;
            cout<<bt ->data;
        }
        if (top != -1)
        {
            s[top].flag = 2;
            bt = s[top].ptr -> rchild;
        }
        else break;
    }
}