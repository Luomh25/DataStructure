#include <iostream>
#include "InThr.h"
using namespace std;

template<typename T>
InThrBitree<T>::InThrBitree()       //建立二叉树
{
    ThrNode<T> * pre;
    root = NULL;
    root = Creat(root);
    pre = NULL;
    ThrBitree(root, pre);
}

template<typename T>  
InThrBitree<T>::~InThrBitree()
{
    Release(root);
}   

template<typename T>
void InThrBitree<T>::Release(ThrNode<T> * bt)
{
    if (bt != NULL)
    {
        if (bt -> ltag == 0)  Release(bt -> lchild);
        if (bt -> rtag == 0)  Release(bt -> rchild);
        delete bt;
    }
}

template <typename T>
ThrNode<T> * InThrBitree<T>::Creat(ThrNode<T> * bt)
{
    char ch;
    cout<<"请输入创建一棵二叉树的结点数据："<<endl;
    cin>>ch;
    if (ch == '#')  return NULL;
    else
    {
        bt = new ThrNode<T>;
        bt -> data = ch;
        bt -> lchild = Creat(bt -> lchild);
        bt -> rchild = Creat(bt -> rchild);
    }
    return bt;
}

template <class DataType>
void InThrBitree<DataType> ::ThrBitree(ThrNode<DataType> *&bt, ThrNode<DataType> *&pre)
{
     if (bt == NULL) return ;
     ThrBitree(bt -> lchild, pre);
     if (bt -> lchild == NULL)
     {
         bt -> ltag = Thread;   
         bt -> lchild = pre;
     }
     if (bt -> rchild == NULL) bt -> rtag = Thread;
     if (pre != NULL && pre -> rtag == 1)  pre -> rchild = bt;
     pre = bt;
     ThrBitree(bt -> rchild, pre);
}

template <class DataType>
ThrNode<DataType> * InThrBitree<DataType>::Next(ThrNode<DataType> * p)
{
    ThrNode<DataType> * q;
    if (p -> rtag == 1)  q = p -> rchild;
    else
    {
        q = p -> rchild;
        while (q -> ltag == 0)
            q = q -> lchild;
    }
    return q;
}

template <class DataType>
void InThrBitree<DataType>::InOrder( )
{ 
    ThrNode<DataType> * p;
    if (root == NULL) return;
    p = root;
    while (p -> ltag == 0)  p = p -> lchild;
    cout<<p -> data;
    while (p -> rchild != NULL)
    {
        p = Next(p);
        cout<<p -> data; 
    }
}
