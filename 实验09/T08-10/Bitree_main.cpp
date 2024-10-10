#include <iostream>
using namespace std;
#include "Bitree.cpp"

int main()
{	
	Bitree T; //创建一棵树
	cout<<"------前序遍历------ "<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	T.InOrder();
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;
	T.PostOrder();
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	T.LeverOrder();
	cout<<endl;
    int n = T.countLeaves();
    cout<<"叶子数为："<<n<<endl;
    cout<<"叶子结点为：";leavesPrint(T.getRoot());
    cout<<endl;
    int n1 = T.countNode();
	cout<<"节点数为："<<n1<<endl;
    int n2 = Depth(T.getRoot());
	cout<<"深度为："<<n2<<endl;
	return 0;
}
