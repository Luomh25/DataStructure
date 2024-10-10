#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Bitree.cpp"

int a[Len] = {0};

void Creat() // 生成随机数组
{
	srand(time(NULL));
	for (int i = 0; i < Len; i++)
	{
		a[i] = 1 + rand() % Max;
		for (int j = 0; j < i; j++)
			if (a[i] == a[j])  a[i]++;
	}
}

int main()
{
	Creat();
	for (int i = 0; i < Len; i++)  cout<<a[i]<<" ";
	int k = 0;
	Bitree T(a, Len);
	cout<<endl<<"中序输出树："<<endl;T.InOrder();
	cout<<endl;
	cout<<"输入查找对象："<<endl;
	cin >> k;
	BiNode *p = T.Search(k);
	if (p == NULL)  cout<<"查找失败！"<<endl;
	else  cout<<"查找对象在第"<<T.Level(k)<<"层"<<endl;
	return 0;
}
