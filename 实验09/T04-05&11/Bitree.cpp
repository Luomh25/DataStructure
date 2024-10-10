#include <iostream>
#include "Bitree.h"
using namespace std;

Bitree::Bitree()
{
    root = NULL;
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

BiNode *Bitree::Creat(BiNode *bt)
{
    char ch;
    cout<<"请输入创建一棵二叉树的结点数据："<<endl;
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

void Bitree::LeverOrder()
{
    int front=-1,rear=-1;
    BiNode *Q[MaxSize],*q;
    if (root == NULL) return;
    else
    {
        Q[++rear] = root;
        while (front != rear)
        {
            q = Q[++front];
            cout<<q->data<<" ";
            if (q -> lchild != NULL)
                Q[++rear] = q->lchild;
            if (q -> rchild != NULL)
                Q[++rear] = q->rchild;
        }
    }   
}

BiNode *Bitree::interface()
{
	int n;
	cout << "输入序列长度\n";
	cin >> n;
	cout << "输入前序序列\n";
	for (int i = 0; i < n ; i++)
	{
		cin >> pre[i];
	}
	cout << "输入中序序列\n";
	for (int i = 0; i < n; i++)
	{
		cin >> pin[i];
	}
	root = create(root, 0, 0, n);
	return root;
}

BiNode *Bitree::create(BiNode * &root, int i1, int i2, int k)
{
    //i1为前序起始下标，i2为中序起始下标，k为序列长度
    if (k <= 0)
    {
        root = NULL;
    }
    else
    {
        root = new BiNode;
        root -> data = pre[i1];
        int m = pos(pre[i1], pin, i2, k);
        int leftlen = m - i2;
        int rightlen = k - (leftlen + 1);
        if (k >= 2)
        {
            while (true)
            {
                int m_next = pos(pre[i1], pin, m+1,rightlen);
                if (m_next != -1)
                {
					int check = pos(pre[i1], pre, i1, leftlen);
					if (check != -1)//如果找得到
					{
						m = m_next;
						leftlen = m - i2;
						rightlen = k - (leftlen + 1);
					}
					else
					{
						break;
					}
				}
                else break;
            }
        }
        create(root->lchild, i1 + 1, i2, leftlen);
        create(root->rchild, i1 + leftlen + 1, m + 1, rightlen);
    }
    return root;
}

int Bitree::pos(char data, char pin[], int i2, int k)  
{
    // 查找值为data, 前序序列pre, 从第i2位开始查找, 查找长度为k
	for (int i = i2; i < i2 + k ; i++)
	{
		if (pin[i] == data)
			return i;
	}
	return -1;
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

void PostOrder(BiNode * root)
{
    if (root != NULL)
    {
        cout<<root->data;
        PostOrder(root->rchild);
        PostOrder(root->lchild);
    }
}