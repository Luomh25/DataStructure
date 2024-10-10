#include <iostream>         //�������������
using namespace std;
#include "LinkStack.cpp"       //�����Ա�����ļ�

int deltax(int i)
{
	if(i<=3) return 1;
	if(i<=6) return -1;
	else return 0;
}
int deltay(int i)
{
	if(i%3==1) return 1;
	if(i%3==2) return -1;
	if(i%3==0) return 0;
}

void migong()
{
	int n,m,a[100][100];
	LinkStack Q;
	bool t[100][100];
	cout<<"�����Թ�������������"<<endl;
	cin>>n>>m;
	cout<<"�������������Թ���0�����·��1�����ϰ����ÿո������"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			t[i][j]=0;
		}	
	}
	for(int j=0;j<=m+1;j++) 
	{
		a[n+1][j]=1;
		a[0][j]=1;
	}
	for(int i=0;i<=n+1;i++)
	{
		a[i][0]=1;
		a[i][m+1]=1;				
	}
	
	if(a[1][1]==1)
	{
		cout<<"ʧ��"<<endl;
		return ;
	}
	Q.Push(1,1,1);
	t[1][1]=1;
	int x,y,d=1;
	while(Q.Empty()==0)
	{	
		Point s=Q.Pop();
		x=s.x,y=s.y,d=s.d;
		while(d<=8)
		{
			int newx = x + deltax(d),newy = y + deltay(d);
			if(x==n && y==m)
			{
				while(Q.Empty()==0)
				{
					Point po=Q.GetTop();
					cout<<"("<<po.x<<","<<po.y<<") ->";
					Q.Pop();
				}
				cout<<"("<<1<<","<<1<<");";
				return ;
			}
			if(t[newx][newy]==0 && a[newx][newy]==0)
			{
				t[newx][newy]=1;
				Q.Push(newx,newy,d);
				x=newx;
				y=newy;
				d=1;
			}
			else
			{
				d++;
			}	
		}
	} 
	cout<<"ʧ��"<<endl; 
	return ;
	
}

int main()
{
	migong();
	return 0;
}
