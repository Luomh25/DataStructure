#include<iostream>
#include<cstdio> 
#include<cstdlib>
#include <stdio.h>
#include <time.h> 
using namespace std;
const int Max = 100;

struct MachineNode
{
	int ID;
	int avail;
}M[Max+1];

struct JobNode
{
	int ID;
	int time;
}J[Max+1];

void Sift(JobNode r[], int k, int m)//大根堆的建立 
{
	int i = k,j = 2*i;
	while(j <= m)
	{
		if( (j < m) && (r[j].time < r[j+1].time))
			j++;
		if( (r[i].time) > (r[j].time))
			break;
		else
		{
			JobNode t = r[i];
			r[i] = r[j];
			r[j] = t;
			i = j;
			j = 2*i;
		}
	}
}

void Sift2(MachineNode r[], int k, int m)//小根堆的建立 
{
	int i = k, j = 2*i;
	while(j <= m)
	{
		if((j < m) && (r[j].avail > r[j+1].avail))
			j++;
		if((r[i].avail) < (r[j].avail))
			break;
		else
		{
			MachineNode t = r[i];
			r[i] = r[j];
			r[j] = t;
			i = j;
			j = 2*i;
		}
	}
}

void LPT(int n, int m)
{
	if(n <= m)
	{
		int maxtime = J[1].time;
		for(int i = 1; i <= m; i++)
		{
			cout<<"把第"<<i<<"个作业分配给机器"<<i<<",用时"<<J[i].time<<endl;
			if( J[i].time > maxtime) 
				maxtime = J[i].time;
		}
		cout<<"最短调度长度为"<<maxtime<<endl;
		return ;
	}
	else
	{
		//n个作业的大根堆 建立 
		int i = 0;
		for(i = n/2; i >= 1; i--)
			Sift(J, i, n);
		i = 1;
		int maxtime = 0;
		while(i <= n)
		{
			//机器建立小根堆 
			Sift2(M, 1, m);
			int t1 = J[1].time;
			int n1 = J[1].ID;
			int n2 = M[1].ID;
			M[1].avail += t1;
			int t2 = M[1].avail;
			cout<<"把第"<<n1<<"个作业分配给机器"<<n2<<",用时"<<t1<<",完成时刻为"<<t2<<endl;			
			//H1的堆顶作业取走,再建立大根堆 
			J[1] = J[n - i + 1]; 	
			Sift(J, 1, n-i);
			i++; 			
		} 
		cout<<"最短调度长度为"<<M[1].avail<<endl;
		return ;
	}
}

int main()
{
	int m, n, i;
	cout<<"请输入机器台数m"<<endl;
	cin>>m; 
	for(int i = 1; i <= m; i++)
	{
		M[i].ID = i;
		M[i].avail = 0; 
	}
	cout<<"请输入作业总数n和每个作业所需时间"<<endl;
	cin>>n;
	cout<<"请输入每个作业所需时间"<<endl;	
	for(int i = 1; i <= n; i++)
	{
		cin>>J[i].time;
		J[i].ID = i;
	}	
	LPT(n, m);
	return 0;
}