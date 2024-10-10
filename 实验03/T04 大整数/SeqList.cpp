#include "SeqList.h"
#include <iostream>           
#include <cstdio> 
using namespace std;

template <class DataType>
int SeqList<DataType> ::Length( )
{
	return length;
}

template <class DataType> 
SeqList<DataType> :: SeqList()
{
  	length = 0;
	for (int i = 0; i < MaxSize; i++)  
  		data[i] = 0;
	sign=1;	
}

template <class DataType>  
SeqList<DataType> :: SeqList(DataType a[ ], int n)
{
	if (n > MaxSize) throw "参数非法";
	for (int i = 0; i < n; i++)  
		data[i] = a[i];
  	length = n;
  	for (int i = n; i < MaxSize; i++)  
  		data[i] = 0;
  	sign=1;
}

template <class DataType>  
SeqList<DataType> :: ~SeqList(){ } 

template <class DataType>  
void SeqList<DataType> :: negtive()
{
	sign=-1;
}

template <class DataType>  
void SeqList<DataType> :: PrintList( )
{
	if(sign==-1) cout<<"-";
	for (int i = length-1; i >=0; i--)
		cout<<data[i];                   
	cout<<endl; 
}

template <class T> 
void BigInt_Abdicate(int l,SeqList<T> &C)
{
	while(C.data[l-1]==0&&l>0)
		l--;
	if(l==0) l++;	
	C.length=l;	
}

template <class T> 
int BigInt_Judge(SeqList<T> A, SeqList<T> B)
{
	int l1=A.length,l2=B.length;
	if(l1<l2) return -1;
	else if(l1>l2) return 1;
	else 
	{
		for(int i=l1-1;i>=0;i--)
		{
			if(A.data[i]<B.data[i]) 
				return -1;
			if(A.data[i]>B.data[i])
				return 1; 
		}
	}
	return 0;
}

template <class T> 
void BigInt_ADD(SeqList<T> A, SeqList<T> B,SeqList<T> &C)
{  
	int n1=A.length,n2=B.length,n=max(n1,n2);
	for(int i=0;i<n;i++)
		C.data[i]=A.data[i]+B.data[i];
	for(int i=0;i<n;i++)
	{
		C.data[i+1]=C.data[i+1]+C.data[i]/10; 
		C.data[i]=C.data[i]%10;
	}
	BigInt_Abdicate(n+1,C);
}

template <class T> 
void BigInt_ABS(SeqList<T> A, SeqList<T> B,SeqList<T> &C)
{
	int l1=A.length;
	for(int i=0;i<l1;i++)
	{
		if(A.data[i]<B.data[i]) 
		{
			A.data[i+1]--;
			A.data[i]=A.data[i]-B.data[i]+10;
		}
		else
		{
			A.data[i]=A.data[i]-B.data[i];
		}
		C.data[i]=A.data[i];
	}
	BigInt_Abdicate(l1,C);
}

template <class T> 
void BigInt_SUB(SeqList<T> A, SeqList<T> B,SeqList<T> &C)
{  
	
	int t=BigInt_Judge(A,B);
	if(t==-1) 
	{
		C.negtive(); 
		BigInt_ABS(B,A,C);
	}
    else
    {
	    BigInt_ABS(A,B,C);
	}
}

template <class T> 
void BigInt_MUL(SeqList<T> A, SeqList<T> B,SeqList<T> &C)
{  
	int l1=A.length,l2=B.length;

	for(int i=0;i<l2;i++)
		for(int j=0;j<l1;j++)
			C.data[i+j]=C.data[i+j]+B.data[i]*A.data[j];

	for(int i=0;i<l1+l2;i++)
	{
		C.data[i+1]=C.data[i+1]+C.data[i]/10; 
		C.data[i]=C.data[i]%10;
	}
	BigInt_Abdicate(l1+l2,C);
}

template <class T> 
void BigInt_DIV(SeqList<T> A, SeqList<T> B,SeqList<T> &C,SeqList<T> &D)
{  	
	int t=BigInt_Judge(A,B);
    if(t==-1) //A<B
	{ 
		D=A;//余数为A
		C.length=1;
		C.data[0]=0;//商为0 
	}
    else//A>=B
    {
		int l1=A.length;
		int i=l1-1;
		SeqList<int> tA;
		for(;i>=0;i--)
		{
			tA.length++; 
			for(int j=tA.length-1;j>=1;j--)
			{
				tA.data[j]=tA.data[j-1];
			}
			tA.data[0]=A.data[i];
			BigInt_Abdicate(tA.length,tA);	
			if(BigInt_Judge(tA,B)!=-1) 
			{
				int k=0;
				SeqList<int> tC,tD;
				tC=tA;
				BigInt_SUB(tC,B,tD);
				while(tD.sign==1)
				{
					k++;
					tC=tD;
					BigInt_SUB(tC,B,tD);
				}
				C.data[i]=k;
				tA=tC;
				BigInt_Abdicate(tA.length,tA);
			}
			if(i==0) 
			{
				D=tA;
			}			
		}
		BigInt_Abdicate(l1,C);
	}
}