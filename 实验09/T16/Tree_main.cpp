#include <iostream>
using namespace std;
#include "Tree.cpp"

int main()
{
	Tree t1;
	t1.PreOrder();
	cout<<endl;
	t1.PostOrder();
	cout<<endl;
	char test = '\0';
	int num = 0;
	cout<<"������ҽڵ�: ";
	cin>>test;
	cout<<"�������λ��: ";
	cin>>num;
	TNode* ans = Search(t1.getRoot(), test, num);
	t1.info(ans);
	return 0;
}