#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
const int Max = 10000;

void Creat(int r[], int n);
void Creat1(int r[], int n);
void Creat2(int r[], int n);
void InsertSort(int r[], int n);
void ShellSort(int r[], int n);
void BubbleSort(int r[], int n);

int Partition(int r[], int first, int end);
void QuickSort(int r[], int first, int end);

void SelectSort(int r[], int n);

void Sift(int r[], int k, int m);
void HeapSort(int r[], int n);

void Merge(int r[], int r1[], int s, int m, int t);
void MergeSort2(int r[], int r1[], int s,int t);

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

void timecom()
{
	int k=50,A[Max+1],b[Max+1];
	cout<<"对"<<k<<"组数排序，每组数有"<<Max<<"个"<<endl; 
	clock_t start_t, end_t;
	double total_t=0;
	for(int i=1;i<=k;i++)
	{
		Creat(b,Max); 
		start_t = clock();
		InsertSort(b,Max);
		end_t = clock();
		total_t=total_t-start_t+end_t;
	}
	total_t = (double) total_t / CLOCKS_PER_SEC;
	cout<<"直接插入排序:   "<<setw(3)<<total_t<<"秒"<<endl;

	for(int i=1;i<=k;i++)
	{
		Creat(b,Max); 
		start_t = clock();
		ShellSort(b, Max);
		end_t = clock();
		total_t=total_t-start_t+end_t;
	}
	total_t = (double) total_t / CLOCKS_PER_SEC;	
	cout<<"希尔排序：      "<<setw(3)<<total_t<<"秒"<<endl;

	for(int i=1;i<=k;i++)
	{
		Creat(b,Max); 
		start_t = clock();
		BubbleSort(b, Max);	
		end_t = clock();
		total_t=total_t-start_t+end_t;
	}
	total_t = (double) total_t / CLOCKS_PER_SEC;	
	cout<<"起泡排序：      "<<setw(3)<<total_t<<"秒"<<endl;

	for(int i=1;i<=k;i++)
	{
		Creat(b,Max); 
		start_t = clock();
		QuickSort(b,1,Max);
		end_t = clock();
		total_t=total_t-start_t+end_t;
	}
	total_t = (double) total_t / CLOCKS_PER_SEC;
	cout<<"快速排序：      "<<setw(3)<<total_t<<"秒"<<endl;

	for(int i=1;i<=k;i++)
	{
		Creat(b,Max); 
		start_t = clock();
		SelectSort(b, Max);
		end_t = clock();
		total_t=total_t-start_t+end_t;
	}
	total_t = (double) total_t / CLOCKS_PER_SEC;
	cout<<"直接选择排序:   "<<setw(3)<<total_t<<"秒"<<endl;

	for(int i=1;i<=k;i++)
	{
		Creat(b,Max); 
		start_t = clock();
		HeapSort(b, Max);
		end_t = clock();
		total_t=total_t-start_t+end_t;
	}
	total_t = (double) total_t / CLOCKS_PER_SEC;	
	cout<<"堆排序(大根堆)："<<setw(3)<<total_t<<"秒"<<endl;

	for(int i=1;i<=k;i++)
	{
		Creat(b,Max); 
		start_t = clock();
		MergeSort2(b, A, 1, Max);
		end_t = clock();
		total_t=total_t-start_t+end_t;
	}
	total_t = (double) total_t / CLOCKS_PER_SEC;	
	cout<<"归并排序：      "<<setw(3)<<total_t<<"秒"<<endl;
}

int main( )
{
	srand(time(NULL));
	timecom();
	return 0;
}

void Creat(int r[], int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)        //r[0]可能用作哨兵 
		r[i] = 1 + rand() % 100;
}

void InsertSort(int r[], int n)    //0号单元用作暂存单元和监视哨
{	
	for (int i = 2; i <= n; i++)
	{ 
		r[0]=r[i]; 	//暂存待插关键码，设置哨兵
		int j;          
		for ( j = i - 1; (r[0] < r[j]); j--)   //寻找插入位置
		{
			r[j + 1] = r[j];            //记录后移
		}
		r[j + 1] = r[0];	
	}
}

void ShellSort(int r[], int n)    //0号单元用作暂存单元
{
	for (int d = n/2; d >= 1; d = d / 2)   //以增量为d进行直接插入排序
	{
		for (int i = d + 1; i <= n; i++)   
		{   
			r[0] = r[i];    //暂存被插入记录
			int j ; 
			for ( j = i - d; j > 0 && r[0] < r[j]; j = j - d)
			{
				r[j + d] = r[j];         //记录后移d个位置
			}
			r[j + d] = r[0];
		}
	}
}

void BubbleSort(int r[], int n)    //0号单元用作交换操作的暂存单元
{	
	int exchange = n, bound = n;   //第一趟起泡排序的区间是[1, n]
	while (exchange != 0)        //当上一趟排序有记录交换时
	{
		bound = exchange; exchange = 0;  
		for (int j = 1; j < bound; j++)     //一趟起泡排序，排序区间是[1, bound]
			if (r[j] > r[j+1])
			{
				r[0] = r[j]; r[j] = r[j + 1]; r[j + 1] = r[0];
				exchange = j;         //记载每一次记录交换的位置
			}
	}
}

int Partition(int r[], int first, int end)
{	
	int i = first, j = end;         //初始化
	while (i < j)	
	{  
		while (i < j && r[i] <= r[j]) j--;  //右侧扫描
		if (i < j)
		{
			r[0] = r[i]; r[i] = r[j]; r[j] = r[0];
			i++; 
		}
		while ( i < j && r[i] <= r[j]) i++;  //左侧扫描
		if (i < j)
		{
			r[0] = r[i]; r[i] = r[j]; r[j] = r[0];
			j--; 
		}
	}
	return i;    //i为轴值记录的最终位置
}

void QuickSort(int r[], int first, int end)
{	

	if (first < end)
	{      //区间长度大于1，执行一次划分，否则递归结束
		int pivot=Partition(r, first, end);    //一次划分
		QuickSort(r, first, pivot - 1);     //递归地对左侧子序列进行快速排序
		QuickSort(r, pivot + 1, end);     //递归地对右侧子序列进行快速排序
	}
}

void SelectSort(int r[], int n)   //0号单元用作交换操作的暂存单元
{   
	
	for (int i = 1; i < n; i++)  	 //对n个记录进行n-1趟简单选择排序
	{  
		int index = i; 		
		for (int j = i + 1; j <= n; j++)   //在无序区中选取最小记录
			if ( r[j] < r[index]) index = j;
		if (index != i) 
		{
			r[0] = r[i]; r[i] = r[index]; r[index] = r[0];
		}
	}	
}

void Sift(int r[], int k, int m)   //0号单元用作交换操作的暂存单元
{
	int i = k, j = 2 * i;     //i指向被筛选结点，j指向结点i的左孩子
	while (j <= m)             //筛选还没有进行到叶子
	{
		if (  j < m && r[j] < r[j+1]) j++;  //比较i的左右孩子，j指向较大者
		if ( r[i] > r[j]) break;         //根结点已经大于左右孩子中的较大者
		else
		{
			r[0] = r[i]; r[i] = r[j]; r[j] = r[0];   //将根结点与结点j交换
			i = j; j = 2 * i;           //被筛结点位于原来结点j的位置
		}
	}
}

void HeapSort(int r[], int n)      //0号单元用作交换操作的暂存单元
{
	
	int i = 0;
	for (i = n/2; i >= 1; i--)       //初始建堆，从最后一个分支结点至根结点
		Sift(r, i, n); 
    for (i=1; i<n; i++)         //重复执行移走堆顶及重建堆的操作
    {
		r[0] = r[1]; r[1] = r[n - i + 1]; r[n - i + 1] = r[0];
		Sift(r, 1, n-i);
	}
}

void Merge(int r[], int r1[], int s, int m, int t)
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j])
			r1[k++] = r[i++];
		else r1[k++] = r[j++];
	}
	if (i <= m)
		while (i <= m)
			r1[k++] = r[i++];
	else
		while (j <= t)
			r1[k++] = r[j++];
}

void MergeSort2(int r[], int r1[], int s,int t)
{
	if (s != t)
	{
		int m = (s + t) / 2;
		MergeSort2(r, r1, s, m);
		MergeSort2(r, r1, m + 1, t);		
		for (int i = s; i <= t; i++)
		{
			r1[i] = r[i];
		}
		Merge(r1, r, s, m, t);
	}
}