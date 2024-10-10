#include<iostream>   
#include<cstdio>
#include"LinkList.cpp" 
using namespace std;
int main()
{
    int ta[1000],tn;
    cout<<"请输入集合A的长度：";
    cin>>tn;
    cout<<"请按顺序键入集合A的元素：";
    for (int i = 0; i < tn; i++)
        cin>>ta[i];
    LinkList<int> A1(ta,tn),A2(ta,tn),A3(ta,tn);

    cout<<"请输入集合B的长度：";
    cin>>tn;
    cout<<"请按顺序键入集合B的元素：";
    for (int i = 0; i < tn; i++)
        cin>>ta[i];
    LinkList<int> B1(ta,tn),B2(ta,tn),B3(ta,tn);
    //判断相等
    if (IsEqual(A1,B1) == 1)
        cout<<"A,B集合相等"<<endl;
    else cout<<"A,B集合不相等"<<endl;
    //求交集
    Interest(A1,B1);
    cout<<"A,B的交集是："<<endl;B1.PrintList();
    //求并集
    unionList(A2,B2);
    cout<<"A,B的并集是："<<endl;A2.PrintList();
	//求差集
    cout<<"A,B的差集是："<<endl;
    if(A3.Length()>B3.Length()) 
	{
		Difference(A3,B3);
		A3.PrintList();
	}
    else 
	{
		Difference(B3,A3);
		B3.PrintList();
	}
    return 0;
}
