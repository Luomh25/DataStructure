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
	int k = 0, k1, k2;
	Bitree T(a, Len);
	cout<<endl<<"中序输出树："<<endl;T.InOrder();
	cout<<endl;
	cout<<"输入2个查找对象："<<endl;
	cin>>k1>>k2;
	cout<<"最近公共祖先为"<<(T.Ancestor(k1, k2) -> data)<<endl;
	return 0;
}
