#include <iostream>
#include <cstdio>
using namespace std;
#include "Bitree.h"

Bitree::Bitree(int a[], int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
	{
		BiNode *s = new BiNode;
		s -> data = a[i];
		InsertBST(root, s);
	}
}

Bitree::~Bitree()
{
	Release(root);
}

void Bitree::Insert(int k)
{
	BiNode *s = new BiNode;
	s -> data = k;
	InsertBST(root, s);
}

void Bitree::InsertBST(BiNode *&root, BiNode *s)
{
	if (root == NULL)
	{
		root = s;
		root -> lchild = NULL;
		root -> rchild = NULL;
	}
	else if (s -> data < root -> data)  InsertBST(root -> lchild, s);
	else  InsertBST(root -> rchild, s);
}

void Bitree::DeleteBST(BiNode *p, BiNode *f)
{
	f -> lchild = NULL;
	Release(p);
}

BiNode *Bitree::Search(int k)
{
	return SearchBST(root, k);
}

BiNode *Bitree::SearchBST(BiNode *root, int k)
{
	if (root == NULL)  return NULL;
	else if (root -> data == k)  return root;
	else if (root -> data > k)  return SearchBST(root -> lchild, k);
	else  return SearchBST(root -> rchild, k);
}

int Bitree::Level(int k)
{
	return LevelBST(root, Search(k));
}

int Bitree::LevelBST(BiNode *root, BiNode *p)
{
	if (p == NULL)  return 0;
	if (p == root)  return 1;
	else if (root -> data > p -> data)  return LevelBST(root -> lchild, p) + 1;
	else  return LevelBST(root -> rchild, p) + 1;
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

void Bitree::PreOrder(BiNode *bt)
{
	if (bt == NULL)  return;
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
