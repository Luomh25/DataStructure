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
	cout<<"输入查找节点: ";
	cin>>test;
	cout<<"输入查找位置: ";
	cin>>num;
	TNode* ans = Search(t1.getRoot(), test, num);
	t1.info(ans);
	return 0;
}