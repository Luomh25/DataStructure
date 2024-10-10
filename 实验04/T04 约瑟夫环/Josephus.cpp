#include<iostream>
using namespace std;
#include "SeqList.cpp"

int main()
{
	int n,m;
	cout<<"Input n(the total number of people)"<<endl;
	cin>>n;
	cout<<"Input m(the password)"<<endl;
	cin>>m;
	SeqList<int> a(n);
	a.Joseph(m);
	return 0;
}