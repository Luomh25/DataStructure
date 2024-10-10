#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXINT=9999;

struct element
{
	int weight;                 //Ȩ�� 
	char c;                     //��ĸ 
	int lchild,rchild,parent;   //���Һ��ӣ�Ĭ�������Һ��Ӽ�Ϊ-1����˫�ס� 
};

element huffTree[100]; 
int number[100][100],l[100];
//l[0] ��ʾA�Ĺ�������ĳ��ȣ�����Ϊ0˵���ĵ�����û�й������� 
//number[0] ��ʾA�Ĺ�������
//ѡ����С�������������Ϊi1��i2 

void Select(element huffTree[], int &i1, int &i2, int n)
{
	for(int i = 0; i < 2*n-1; i++)
	{
		if(huffTree[i].parent == -1)
		{
			i1 = i;
			break;
		}
	}
	for(int i = 0; i < 2*n-1; i++)
	{
		if(huffTree[i].parent != -1)  continue;	
		if(huffTree[i].weight < huffTree[i1].weight)  i1 = i;
	}	
	for(int i = 0; i < 2*n-1; i++)
	{
		if(huffTree[i].parent == -1 && i != i1)
		{
			i2 = i;
			break;
		}
	}	
	for(int i = 0; i < 2*n-1; i++)
	{
		if(huffTree[i].parent != -1 || i == i1)  continue;	
		if(huffTree[i].weight < huffTree[i2].weight)  i2=i;
	}		
}

//���
void show(element huffTree[], int n, char a[])
{
	for(int k = 0; k < 2*n-1; k++)
	{
		cout<<k<<":"<<huffTree[k].c<<' '<<huffTree[k].weight<<" "<<huffTree[k].parent
		<<" "<<huffTree[k].lchild<<" "<<huffTree[k].rchild<<endl;
	}
	cout<<endl;
}


void HuffmanTree(element huffTree[], int w[], int n, char a[])//������������ 
{
	for(int i = 0; i < 2*n-1; i++)//��ʼ�� 
	{
		huffTree[i].parent = -1;
		huffTree[i].rchild = -1;
		huffTree[i].lchild = -1;
		huffTree[i].weight = MAXINT;
		huffTree[i].c = ' ';
	}
	for(int i = 0; i < n; i++)
	{
		huffTree[i].weight = w[i];
		huffTree[i].c = a[i];
	}
	for(int k = n; k < 2*n-1; k++)
	{
		int i1,i2;
		Select(huffTree, i1, i2, n);
		huffTree[i1].parent = k;
		huffTree[i2].parent = k;
		huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
		huffTree[k].lchild = i1;
		huffTree[k].rchild = i2;
	}
}

void getw(string &s, char a[], int w[], int &n)
{
	cout<<"�������ĵ�"<<endl;
	int tw[100];
	for(int i = 0; i < 26; i++)  tw[i] = 0;
	cin>>s;
	for(int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if(c == '#')  break;
		tw[c-'A']++;
	}
	n = 0;
 	for(int i = 0; i < 26; i++)
	{
		if(tw[i] != 0) 
		{
			w[n] = tw[i];
			a[n] = i+'A';
			n++;
		}
	}		
} 

void HuffmanCode(int k, int d, int num[])//�ݹ�õ�ÿ����ĸ�Ĺ������� 
{
	if(huffTree[k].c == ' ')
	{
		num[d] = 0;
		num[d] = 0;
		HuffmanCode(huffTree[k].lchild, d+1, num);
		num[d] = 1;
		HuffmanCode(huffTree[k].rchild, d+1, num);
		return;
	}
	else 
	{
		char tc = huffTree[k].c;
		cout<<huffTree[k].c<<"�ı���Ϊ";
		//����ÿ����ĸ�Ĺ�������		
		for(int i = 0; i < d; i++)
		{
			cout<<num[i];
			number[tc-'A'][i] = num[i];
		}	
		l[tc-'A'] = d;
		cout<<endl;
	}	
}

void  DeHuffmanCode(int sn,int n,int scode[])
{
	int i = 0;
	int now = 2*n-1-1;
	while(i < sn)
	{				
		int next = huffTree[now].rchild;
		if(scode[i] == 0)  next = huffTree[now].lchild;
		int nl = huffTree[next].lchild;
		int nr = huffTree[next].rchild;
		if(nl == -1 && nr == -1)
		{
			cout<<huffTree[next].c;
			now = 2*n-1-1;
		}	
		else  now=next;
		i++;
	}	
}

int main()
{
	for(int i=0;i<100;i++)  l[i]=0;
	int w[100], n;
	char a[100];
	for(int i = 0; i < 100; i++)  a[i]=' '; 
	string s;
	getw(s,a,w,n);
	HuffmanTree(huffTree, w, n, a);
	int num[100];
	HuffmanCode(2*n-1-1, 0, num);
	cout<<endl<<"���ĵ����й�����ѹ�����룺"<<endl; 
	int scode[10000]; 
	int sn = 0;
	for(int i = 0; i < s.length(); i++)
	{
		int k = s[i]-'A';
		for(int i = 0; i < l[k]; i++)
		{
			cout<<number[k][i];
			scode[sn] = number[k][i];
			sn++;
		}				
	}
	cout<<endl; 
	cout<<endl<<"�Զ����������룺"<<endl; 
	DeHuffmanCode(sn, n, scode);
	return 0;
}