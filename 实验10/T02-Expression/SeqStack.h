#ifndef SEQSTACK_H
#define SEQSTACK_H
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int StackSize = 100;

struct BiNode
{
	char data;
	BiNode *lchild,*rchild;
};

template<class T>
class SeqStack
{
    private:
        T data[StackSize];
        int top;
    public:
        SeqStack();
        ~SeqStack();
        void Push(T x);
        T Pop();
        T GetTop();
        int Empty();
        friend int prevalue(string s,SeqStack<int> &num,SeqStack<char> &sign);
		friend void postfix(string& s,SeqStack<int> &num,SeqStack<char> &sign,string &posts,int &lp);
		friend int postvalue(string s,int l);
};

class Bitree
{
	public:
		Bitree();
		Bitree(char post[],int lp);
		~Bitree();
		void PreOrder();
		void InOrder();
		void PostOrder();
	private:
		BiNode *root;
		BiNode *Creat(BiNode *bt);
		void Release(BiNode *bt);
		void PreOrder(BiNode *bt);
		void InOrder(BiNode *bt);
		void PostOrder(BiNode *bt);
};

#endif
