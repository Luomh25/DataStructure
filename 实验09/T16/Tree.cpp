#include <iostream>
using namespace std;
#include "Tree.h"

Tree::Tree()
{
	TNode *Q[Max] = {NULL};
	char ch1 = '#', ch2 = '#';
	int front = -1, rear = -1;
	TNode *p = NULL, *q = NULL;
	cout<<"���������㣺";
	cin>>ch1;
	p = new TNode; p -> data = ch1; 
	p -> firstchild = p -> rightsib = NULL;
	root = p;
	Q[++rear] = p;
    cout<<"��������ԣ��Կո�ָ���";
	fflush(stdin);
    ch1 = getchar(); getchar(); ch2 = getchar();
	while (ch1 != '#' || ch2 != '#')
	{
		p = new TNode; p -> data = ch2; 
		p -> firstchild = p -> rightsib = NULL;
		Q[++rear] = p;
		while (front < rear)
		{
			q = Q[front + 1];
			if (q -> data != ch1)
				front++;
			else 
			{
				if (q -> firstchild == NULL)
					q -> firstchild = p;
				else
				{
					q = q -> firstchild;
					while (q -> rightsib != NULL)
					{
						q = q -> rightsib;
					}
					q -> rightsib = p;
				}
				break;
			}
		}
		cout<<"��������ԣ��Կո�ָ���";
		fflush(stdin);  // �ٴ���ռ��̻�����
        ch1 = getchar(); getchar(); ch2 = getchar();
	}
}

Tree::~Tree()
{
	Release(root);
}

void Tree::PreOrder()
{
	PreOrder(root);
}

void Tree::PostOrder()
{
	PostOrder(root);
}

TNode *Tree::getRoot()
{
	return root;
}

void Tree::Release(TNode *bt)
{
	if (bt == NULL)  return;
	else
	{
		Release(bt->firstchild);
		Release(bt->rightsib);
		delete bt;
	}
}

void Tree::PreOrder(TNode *bt)
{
	if (bt == NULL)  return;
	else
	{
		cout<<bt->data;
		PreOrder(bt->firstchild);
		PreOrder(bt->rightsib);
	}
}

void Tree::PostOrder(TNode *bt)
{
	if (bt == NULL)  return;
	else
	{
		PostOrder(bt->firstchild);
		  
		cout<<bt->data;
		PostOrder(bt->rightsib);
	}
}

TNode * Search(TNode * root, char x, int i)
{
	TNode * p = NULL;
    if (root->data == x)
    {
        int j = 1;
        p = root -> firstchild;
        while (p != NULL && j < i)
        {
            j++;
            p = p -> rightsib;
        }
        if (p != NULL)  return p;
        else  return NULL;
    }
    Search(root->firstchild, x, i);
    if (p != NULL)  Search(root->rightsib, x, i);
}

void Tree::info(TNode *bt)
{
	if (bt)  cout<<"�ýڵ�: "<<bt->data<<endl;
	else  cout<<"������."<<endl;
}