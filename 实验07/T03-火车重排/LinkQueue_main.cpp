#include <iostream>       //�������������
using namespace std;
#include "LinkQueue.cpp"    //�����Ա�����ļ�


void chongpai(int n,int k,int a[])
{
	LinkQueue <int> Q[k];
	int out=1;
	for(int i=n;i>=1;i--)
	{
		int num=a[i];
		if(num==out)
		{
			cout<<"���죺"<<out<<" ֱ�ӳ���  "<<endl;
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
						cout<<"���죺"<<out<<" �� "<<i+1<<" ����� "<<endl;
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
					cout<<"����ʧ��"<<endl;
					return ;
				}		
				else
				{
					Q[oup].EnQueue(num);	
					cout<<"��죺"<<num<<" ���� "<<oup+1<<" ���"<<endl;
				}				
			}
			else
			{
				Q[po].EnQueue(num);
				cout<<"��죺"<<num<<" ���� "<<po+1<<" ���"<<endl;
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
