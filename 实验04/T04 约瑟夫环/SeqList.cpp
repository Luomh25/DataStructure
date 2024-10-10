#include <iostream>
#include "SeqList.h"
#include <cstdio>
using namespace std;

template <class DataType>
SeqList<DataType>::SeqList()
{
	length = 0;
}

template <class DataType>
SeqList<DataType>::SeqList(int n)
{
	for (int i=0;i<n;i++)
		data[i]=i;
	length=n;
}

template <class DataType>  
SeqList<DataType> :: ~SeqList(){ } 

template <class DataType>  
void SeqList<DataType> :: Joseph(int m)
{
	bool b[MaxSize]={0};
	int n=length,count=0;
	int i=0;
	while(length!=0)
	{
		i++;
		if(i==n+1) i=1;
		if(b[i]==1) continue;
		count++;	
		if(count==m)
		{
			b[i]=1;
			cout<<i<<" ";
			length--;
			count=0;
		}
	}
} 