#include <iostream>       //引用输入输出流
using namespace std;
#include "LinkQueue.cpp"    //引入成员函数文件


void chongpai(int n,int k,int a[])
{
	LinkQueue <int> Q[k];
	int out=1;
	for(int i=n;i>=1;i--)
	{
		int num=a[i];
		if(num==out)
		{
			cout<<"出轨："<<out<<" 直接出轨  "<<endl;
			out++;
			
			int t=1,pos;
			while(t==1)
			{
				t=0;
				for(int i=0;i<k;i++)
				{
					if(Q[i].Empty()==1) continue;
					if(Q[i].GetQueue()==out)
					{
						cout<<"出轨："<<out<<" 从 "<<i+1<<" 轨道出 "<<endl;
						t=1;
						Q[i].DeQueue();
						out++; 
						break;	
					}
				}
			}
		}
		else
		{
			int before=-1,po=0;
			for(int i=0;i<k;i++)
			{
				if(Q[i].Empty()==1) continue;
				if(Q[i].GetQueuetail()<num&&Q[i].GetQueuetail()>before)
				{
					before=Q[i].GetQueuetail();
					po=i;
				}
			}
			if(before==-1)
			{
				int emp=0,oup;
				for(int i=0;i<k;i++)
				{
					if(Q[i].Empty()==1)
					{
						emp=1;
						oup=i;
						break;
					}	
				}
				if(emp==0) 
				{
					cout<<"重排失败"<<endl;
					return ;
				}		
				else
				{
					Q[oup].EnQueue(num);	
					cout<<"入轨："<<num<<" 进入 "<<oup+1<<" 轨道"<<endl;
				}				
			}
			else
			{
				Q[po].EnQueue(num);
				cout<<"入轨："<<num<<" 进入 "<<po+1<<" 轨道"<<endl;
			}				 
		}	
	}
}
int main()
{
	int n,k;
	int a[100];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	chongpai(n,k,a); 
	return 0;
}
