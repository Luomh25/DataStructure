#include <iostream>
using namespace std;
#include "Bitree.cpp"

int main()
{	
	Bitree T; //����һ����
	BiNode * p = NULL;
	cout<<"------ǰ�����------ "<<endl;T.PreOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;T.InOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;T.PostOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;T.LeverOrder();
	//T12
	cout<<endl;
	char test = '\0';
	cout<<"������ҽڵ�: "<<endl;
	cin>>test;
	Parent(T.getRoot(), test, p);T.info(p);
	cout<<"Ϊ˫�׽ڵ�."<<endl;
	//T14
	cout<<endl;
	Exchange(T.getRoot());
	cout<<"-----------EXCHANGE----------- "<<endl;
	cout<<"------ǰ�����------ "<<endl;T.PreOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;T.InOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;T.PostOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;T.LeverOrder();
	cout<<endl;
	//T13
	cout<<endl;
	cout<<"-----------DELETE----------- "<<endl;
	T.del('D');
	T.InOrder();
	return 0;
}