#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int Maxd = 5;
const int MaxRange = 10;
const int MaxNode = 20;

struct Node
{
	int key[Maxd];
	int next;
};

struct QueueNode
{
	int front;
	int rear;
};

void Creat(Node r[], int n,int m,int d);
void Print(Node r[], int n,int d,int first);
void Print1(Node r[], int n, int d);
void Distribute(Node r[], int n, QueueNode q[], int m, int first, int j);
void Collect(Node r[], int n, QueueNode q[], int m, int &first);
void RadixSort(Node r[], int n, int m, int d,int &first);

int main()
{
	Node r[MaxNode];
	cout<<"please enter the number of record, Maxsize = "<<MaxNode<<endl;
	int n;
	cin>>n;
	cout<<"please enter the number of subkey, Maxsize = "<<Maxd<<endl;
	int d;
	cin>>d;
	cout<<"please enter the limits of subkey (0~m-1), Maxsize = "<<MaxRange<<endl;
	int m;
	cin>>m;
	Creat(r, n, m,d);
	cout<<"origin subkey: "<<endl;
	Print1(r, n, d);
	cout<<endl;
	int first = 0;
	RadixSort(r, n, m, d,first);//必须把first带出来才能得到排序
	system("pause");
	return 0;
}


void Creat(Node r[], int n,int m,int d)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
		for (int j = 0; j < d; j++)
		{
			r[i].key[j] = rand() % m;
		}
}

void Print(Node r[], int n,int d,int first)
{	
	int count = 0;
	while (count<n)
	{
		for (int j = 0; j < d; j++)
		{
			cout<<r[first].key[j]<<' ';
		}
		cout<<endl;
		first = r[first].next;
		count++;
	}		
	cout<<endl;
}

void Print1(Node r[], int n, int d)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cout<<r[i].key[j]<<' ';
		}
		cout<<endl;
	}
		
}

void Distribute(Node r[], int n, QueueNode q[], int m, int first, int j)
{
	int i = first;
	int count=0;
	int k;
	while (count<n)
	{
		k = r[i].key[j];
		if (q[k].front == -1)q[k].front = i;
		else r[q[k].rear].next = i;
		q[k].rear = i;
		i = r[i].next;
		count++;
	}
}

void Collect(Node r[], int n, QueueNode q[], int m, int &first)
{
	int k = 0;
	while (q[k].front == -1)
		k++;
	first = q[k].front;//带出头记录所在下标
	int last = q[k].rear;
	while (k<m)
	{
		k++;
		if (k >= m)break;//k必须小于m
		if (q[k].front != -1)
		{
			r[last].next = q[k].front;
			last = q[k].rear;
		}
	}
	r[last].next = -1;
}

void RadixSort(Node r[], int n, int m, int d,int &first)
{
	for (int i = 0; i < n; i++)
		r[i].next = i + 1;
	r[n - 1].next = -1;
	QueueNode q[MaxRange];	
	for (int j = d - 1; j > -1; j--)
	{
		for (int i = 0; i < m; i++)//对每个子关键码分配前要清空桶
			q[i].front = q[i].rear = -1;
		Distribute(r, n, q, m, first, j);		
		Collect(r, n, q, m, first);
		cout<<"after sorting for "<<d - j<<" times, r["<<n<<"]= "<<endl;
		Print(r, n, d,first);
	}
}