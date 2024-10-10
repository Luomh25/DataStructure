#include <iostream>
using namespace std;
#include "Bitree.cpp"

int main()
{	
	Bitree T; //创建一棵树
	BiNode * p = NULL;
	cout<<"------前序遍历------ "<<endl;T.PreOrder();
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;T.InOrder();
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;T.PostOrder();
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;T.LeverOrder();
	//T12
	cout<<endl;
	char test = '\0';
	cout<<"输入查找节点: "<<endl;
	cin>>test;
	Parent(T.getRoot(), test, p);T.info(p);
	cout<<"为双亲节点."<<endl;
	//T14
	cout<<endl;
	Exchange(T.getRoot());
	cout<<"-----------EXCHANGE----------- "<<endl;
	cout<<"------前序遍历------ "<<endl;T.PreOrder();
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;T.InOrder();
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;T.PostOrder();
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;T.LeverOrder();
	cout<<endl;
	//T13
	cout<<endl;
	cout<<"-----------DELETE----------- "<<endl;
	T.del('D');
	T.InOrder();
	return 0;
}