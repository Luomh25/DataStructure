#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int rrz = 3;

struct element
{
	int D;//�ӽ��i�����i������������˥���������ֵ 
	int d;//���i���丸�׵�˥���� 
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
//	cout<<"�����봴��һ�ö������Ľ������"<<endl;
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
				cout<<"��"<<l->data.c<<"����һ���Ŵ���"<<endl; 
			}	
			else  bt -> data.D = max(bt -> data.D, l -> data.D + l -> data.d);
		}
		l = r;
		if(l != NULL)
		{
			if(l -> data.D + l -> data.d > rrz)
			{
				l -> data.boost = 1;
				cout<<"��"<<l->data.c<<"����һ���Ŵ���"<<endl; 	
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
//	cout<<"����������ֵ"<<endl;
//	cin>>rrz; 
	cout<<"��ʵ������P217Ϊ��������ֵΪ3"<<endl;
	cout<<"���������㵽����˥����������¼�Ƿ��ֹ�Ŵ�����"<<endl; 
	
	T.PostOrder(); 
//	T.PostOrder(); 
	
	return 0;
}