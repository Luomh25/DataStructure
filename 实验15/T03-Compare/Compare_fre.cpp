#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
const int Max = 10;
void Creat(int r[], int n);
void Creat1(int r[], int n);
void Creat2(int r[], int n);
void InsertSort(int r[], int n);
void ShellSort(int r[], int n);
void BubbleSort(int r[], int n);

int Partition(int r[], int first, int end,int& tcom,int &tmove);
void QuickSort(int r[], int first, int end,int& tcom,int& tmove);

void SelectSort(int r[], int n);

void Sift(int r[], int k, int m,int& tcom,int& tmove);
void HeapSort(int r[], int n,int& tcom,int& tmove);

void Merge(int r[], int r1[], int s, int m, int t,int& tcom,int& tmove);
void MergeSort2(int r[], int r1[], int s,int t,int& tcom,int& tmove);

void Copy(int a[],int b[])
{
	for (int i = 1; i <= Max; i++)
		b[i] = a[i];	
}

void show(int a[])
{
    for (int i = 1; i <= Max; i++)
		cout<<a[i]<<"  ";
	cout<<endl;	
}

void timecom(int a[])
{
	int b[Max + 1];
	
	//对与a相同的临时数组b进行排序 
	Copy(a,b);
	cout<<"直接插入排序:   ";
	InsertSort(b, Max);
	Copy(a,b);
	cout<<"希尔排序：      ";
	ShellSort(b, Max);
	Copy(a,b);
	cout<<"起泡排序：      ";
	BubbleSort(b, Max);	

	Copy(a,b);
	cout<<"快速排序：      ";
	int tcom=0,tmove=0;
	QuickSort(b,1,Max,tcom,tmove);
	cout<<"比较次数为"<<setw(3)<<tcom<<",移动次数为"<<setw(3)<<tmove<<endl;		

	Copy(a,b);
	cout<<"直接选择排序:   ";
	SelectSort(b, Max);
	
	Copy(a,b);
	cout<<"堆排序(大根堆)：";
	tcom=0;tmove=0;
	HeapSort(b, Max,tcom,tmove);
	cout<<"比较次数为"<<setw(3)<<tcom<<",移动次数为"<<setw(3)<<tmove<<endl;		
	
	Copy(a,b);
	cout<<"归并排序：      ";
	tcom=0;tmove=0;
	int r1[Max + 1];
	MergeSort2(b, r1, 1, Max,tcom,tmove);
	cout<<"比较次数为"<<setw(3)<<tcom<<",移动次数为"<<setw(3)<<tmove<<endl;		
}

int main( )
{
	srand(time(NULL));
	int a[Max + 1] = {0}, b[Max + 1] = {0};
	cout<<"对于正序序列：";
	Creat1(a, Max);	
	show(a);	
	timecom(a);
	cout<<endl<<"对于逆序序列：";
	Creat2(a, Max);	
	show(a);
	timecom(a);	
	cout<<endl<<"对于随机序列：";
	Creat(a, Max);	
	show(a);
	timecom(a);			
	return 0;
}

void Creat(int r[], int n)
{
	int i = 0;
	for (i = 1; i <= n; i++) //r[0]没用，可能用作哨兵 
		r[i] = 1 + rand() % 100;
}

void Creat1(int r[], int n)
{
	int i = 0;
	r[0]=0; 
	for (i = 1; i <= n; i++) //r[0]没用，可能用作哨兵 
		r[i] = r[i-1] + rand() % 100;
}

void Creat2(int r[], int n)
{
	int i = 0;
	r[0]=1000; 
	for (i = 1; i <= n; i++) //r[0]没用，可能用作哨兵 
		r[i] = r[i-1] -10- rand() % 100;
}

void InsertSort(int r[ ], int n)   //0号单元用作暂存单元和监视哨
{	
	int tcom=0,tmove=0;
	for (int i = 2; i <= n; i++)
	{ 
		r[0]=r[i]; 	//暂存待插关键码，设置哨兵
		tmove++;
		int j;          
		for ( j = i - 1; (++tcom)&&(r[0] < r[j]); j--)   //寻找插入位置
		{
			r[j + 1] = r[j];            //记录后移
			tmove++;
		}
		r[j + 1] = r[0];
		tmove++;	
	}
	cout<<"比较次数为"<<setw(3)<<tcom<<",移动次数为"<<setw(3)<<tmove<<endl;	
}

void ShellSort(int r[ ], int n)    //0号单元用作暂存单元
{
	int tcom=0,tmove=0;
	for (int d = n/2; d >= 1; d = d / 2)   //以增量为d进行直接插入排序
	{
		for (int i = d + 1; i <= n; i++)   
		{   
			r[0] = r[i];    //暂存被插入记录
			++tmove;
			int j ; 
			for ( j = i - d; ++tcom&&j > 0 && r[0] < r[j]; j = j - d)
			{
				r[j + d] = r[j];         //记录后移d个位置
				++tmove;
			}
			r[j + d] = r[0];
			++tmove;
		}
	}
	cout<<"比较次数为"<<setw(3)<<tcom<<",移动次数为"<<setw(3)<<tmove<<endl;	
}

void BubbleSort(int r[ ], int n)    //0号单元用作交换操作的暂存单元
{	
	int tcom=0,tmove=0;
	int exchange = n, bound = n;   //第一趟起泡排序的区间是[1, n]
	while (exchange != 0)        //当上一趟排序有记录交换时
	{
		bound = exchange; exchange = 0;  
		for (int j = 1; j < bound; j++)     //一趟起泡排序，排序区间是[1, bound]
			if (++tcom&&r[j] > r[j+1])
			{
				r[0] = r[j]; r[j] = r[j + 1]; r[j + 1] = r[0];
				exchange = j;         //记载每一次记录交换的位置
				tmove+=3;
			}
	}
	cout<<"比较次数为"<<setw(3)<<tcom<<",移动次数为"<<setw(3)<<tmove<<endl;	
}

int Partition(int r[ ], int first, int end,int& tcom,int& tmove)
{	
	int i = first, j = end;         //初始化
	while (i < j)	
	{  
		while (i < j&&++tcom  && r[i] <= r[j]) j--;  //右侧扫描
		if (i < j)
		{
			r[0] = r[i]; r[i] = r[j]; r[j] = r[0];
			tmove+=3;
			i++; 
		}
		while (i < j&&++tcom  && r[i] <= r[j]) i++;  //左侧扫描
		if (i < j)
		{
			r[0] = r[i]; r[i] = r[j]; r[j] = r[0];
			tmove+=3;
			j--; 
		}
	}
	return i;    //i为轴值记录的最终位置
}

void QuickSort(int r[ ], int first, int end,int &tcom,int &tmove)
{	

	if (first < end)
	{      //区间长度大于1，执行一次划分，否则递归结束
		int pivot=Partition(r, first, end,tcom,tmove);    //一次划分
		QuickSort(r, first, pivot - 1,tcom,tmove);     //递归地对左侧子序列进行快速排序
		QuickSort(r, pivot + 1, end,tcom,tmove);     //递归地对右侧子序列进行快速排序
	}
}

void SelectSort(int r[ ], int n)   //0号单元用作交换操作的暂存单元
{   
	int tcom=0,tmove=0;
	
	for (int i = 1; i < n; i++)  	 //对n个记录进行n-1趟简单选择排序
	{  
		int index = i; 		
		for (int j = i + 1; j <= n; j++)   //在无序区中选取最小记录
			if (++tcom && r[j] < r[index]) index = j;
		if (index != i) 
		{
			r[0] = r[i]; r[i] = r[index]; r[index] = r[0];
			tmove+=3;
		}
	}
	cout<<"比较次数为"<<setw(3)<<tcom<<",移动次数为"<<setw(3)<<tmove<<endl;		
}

void Sift(int r[ ], int k, int m,int& tcom,int& tmove)   //0号单元用作交换操作的暂存单元
{
	int i = k, j = 2 * i;     //i指向被筛选结点，j指向结点i的左孩子
	while (j <= m)             //筛选还没有进行到叶子
	{
		if (++tcom && j < m && r[j] < r[j+1]) j++;  //比较i的左右孩子，j指向较大者
		if (++tcom && r[i] > r[j]) break;         //根结点已经大于左右孩子中的较大者
		else
		{
			r[0] = r[i]; r[i] = r[j]; r[j] = r[0];   //将根结点与结点j交换
			tmove+=3; 
			i = j; j = 2 * i;           //被筛结点位于原来结点j的位置
		}
	}
}

void HeapSort(int r[ ], int n,int& tcom,int& tmove)      //0号单元用作交换操作的暂存单元
{
	
	int i = 0;
	for (i = n/2; i >= 1; i--)       //初始建堆，从最后一个分支结点至根结点
		Sift(r, i, n,tcom,tmove); 
    for (i=1; i<n; i++)         //重复执行移走堆顶及重建堆的操作
    {
		r[0] = r[1]; r[1] = r[n - i + 1]; r[n - i + 1] = r[0];
		tmove+=3;
		Sift(r, 1, n-i,tcom,tmove);
	}
}

void Merge(int r[], int r1[], int s, int m, int t,int& tcom,int& tmove)
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (++tcom && r[i] <= r[j])
			r1[k++] = r[i++];
		else r1[k++] = r[j++];
		tmove++;
	}
	if (i <= m)
		while (i <= m)
		{
			r1[k++] = r[i++];
			tmove++;	
		}
	else
		while (j <= t)
		{
			r1[k++] = r[j++];
			tmove++;
		}
}

void MergeSort2(int r[], int r1[], int s,int t,int& tcom,int& tmove)
{
	if (s != t)
	{
		int m = (s + t) / 2;
		MergeSort2(r, r1, s, m,tcom,tmove);
		MergeSort2(r, r1, m + 1, t,tcom,tmove);		
		for (int i = s; i <= t; i++)
		{
			r1[i] = r[i];
			tmove++;
		}
		Merge(r1, r, s, m, t,tcom,tmove);
	}
}
