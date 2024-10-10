#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int rrz = 3;

struct element
{
	int D;//从结点i到结点i的任意子树的衰减量的最大值 
	int d;//结点i到其父亲的衰减量 
	char c;
	bool boost;
};

struct BiNode
{
	element data;	
	BiNode *lchild,*rchild;	
};

class Bitree
{
	public:
		Bitree(){root = Creat(root);}
		~Bitree(){Release(root);}
		void PostOrder(){PostOrder(root);}
	private:
		BiNode *root;
		BiNode *Creat(BiNode *bt);
		void Release(BiNode *bt);
		void PostOrder(BiNode *bt);
};

BiNode *Bitree::Creat(BiNode *bt)
{
	int k;
//	cout<<"请输入创建一棵二叉树的结点数据"<<endl;
	cin>>k;
	if(k == -1) return NULL;
	else
	{
		bt = new BiNode;
		bt -> data.d = k;
		cin>>bt -> data.c;
		bt -> lchild = Creat(bt -> lchild);
		bt -> rchild = Creat(bt -> rchild);	
		return bt;
	}
}

void Bitree::Release(BiNode *bt)
{
	if(bt != NULL)
	{
		Release(bt -> lchild);
		Release(bt -> rchild);
		delete bt;
	}
}

int MAX(int x,int y)
{
	return x>y?x:y;
}

void Bitree::PostOrder(BiNode *bt)
{
	if(bt == NULL)
	{
		return ;
	}
	else
	{
		BiNode *l = bt -> lchild;
		BiNode *r = bt -> rchild;
		PostOrder(l);
		PostOrder(r);
		bt -> data.D = 0;
		if(l != NULL)
		{
			if(l -> data.D + l -> data.d > rrz)
			{
				l -> data.boost = 1;
				bt -> data.D = l -> data.D;
				cout<<"在"<<l->data.c<<"处放一个放大器"<<endl; 
			}	
			else  bt -> data.D = max(bt -> data.D, l -> data.D + l -> data.d);
		}
		l = r;
		if(l != NULL)
		{
			if(l -> data.D + l -> data.d > rrz)
			{
				l -> data.boost = 1;
				cout<<"在"<<l->data.c<<"处放一个放大器"<<endl; 	
				bt -> data.D = max(bt -> data.D, l -> data.D);					
			}	
			else  bt -> data.D = max(bt -> data.D, l -> data.D + l -> data.d);
		}
		cout<<bt->data.c<<" "<<bt->data.D<<endl;
	}
}

int main()
{
	freopen("a.txt","r",stdin);
	Bitree T;
//	cout<<"请输入容忍值"<<endl;
//	cin>>rrz; 
	cout<<"以实验书上P217为例，容忍值为3"<<endl;
	cout<<"输出各个结点到根的衰减量，并记录是否防止放大器。"<<endl; 
	
	T.PostOrder(); 
//	T.PostOrder(); 
	
	return 0;
}