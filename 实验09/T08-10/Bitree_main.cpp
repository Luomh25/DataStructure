#include <iostream>
using namespace std;
#include "Bitree.cpp"

int main()
{	
	Bitree T; //����һ����
	cout<<"------ǰ�����------ "<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.InOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.PostOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.LeverOrder();
	cout<<endl;
    int n = T.countLeaves();
    cout<<"Ҷ����Ϊ��"<<n<<endl;
    cout<<"Ҷ�ӽ��Ϊ��";leavesPrint(T.getRoot());
    cout<<endl;
    int n1 = T.countNode();
	cout<<"�ڵ���Ϊ��"<<n1<<endl;
    int n2 = Depth(T.getRoot());
	cout<<"���Ϊ��"<<n2<<endl;
	return 0;
}
