#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Bitree.cpp"

int main()
{
	int a[10] = {18, 27, 40, 63, 42, 55, 99, 24, 91, 6};
	int n = 10, k, k1, k2;
	Bitree T(a, n);
	cout<<endl<<"中序遍历树："<<endl;T.InOrder();
	cout<<endl;
	if (T.SortBiTree() == 1)  cout << "是二叉排序树" << endl;
	else  cout << "不是二叉排序树" << endl;
	return 0;
}
