#include<iostream>  
#include"LinkList.cpp"  
using namespace std;

int main( )
{
	int a[6] = { 7, 4, 23, 9, 8, 5}, b[6], i;
	for (i = 0;i < 6;i++)
		b[i] = a[i];
	cout<<"for unordered list: ";
	for (i = 0; i < 6; i++)
		cout<<a[i]<< " ";
	cout<<endl;
	LinkList L1(a, 6);
	LinkList L2(b, 6);
	L1.PrintList();
	cout<<"after perform StraightSort: "<<endl;
	StraightSort(L1);
	L1.PrintList();
	cout<<"after perform SelectSort: "<<endl;
	SelectSort(L2);
	L2.PrintList();
	return 0;
}
