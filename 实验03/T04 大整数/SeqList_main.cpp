#include <iostream>          
#include <cstring>
#include <cstdio>
#include "SeqList.cpp" 
using namespace std;
int  main( )
{
	string s1,s2;
	int l1,l2,r1[MaxSize],r2[MaxSize]; 
	cout<<"���������A"<<endl;
	cin>>s1;
	cout<<"���������B(��������Ϊ0)"<<endl;
	cin>>s2;
	l1=s1.length();
	l2=s2.length();
	for(int i=0;i<l1;i++)
		r1[l1-i-1]=s1[i]-'0';
	for(int i=0;i<l2;i++)
		r2[l2-i-1]=s2[i]-'0';
	SeqList<int> A(r1, l1);
	SeqList<int> B(r2, l2);
    SeqList<int> C,D,E,F,G;

    BigInt_ADD(A,B,C);
	BigInt_SUB(A,B,D);
	BigInt_MUL(A,B,E);
	BigInt_DIV(A,B,F,G);
	
	cout<<endl<<"A+B=";C.PrintList();
	cout<<endl<<"A-B=";D.PrintList();
	cout<<endl<<"A*B=";E.PrintList();
	cout<<endl<<"A/B��������Ϊ";F.PrintList();
	cout<<endl<<"A/B����Ϊ"; G.PrintList(); 
	
	return 0;
}