#include<iostream>   
#include<cstdio>
#include"LinkList.cpp" 
using namespace std;
int main()
{
    int ta[1000],tn;
    cout<<"�����뼯��A�ĳ��ȣ�";
    cin>>tn;
    cout<<"�밴˳����뼯��A��Ԫ�أ�";
    for (int i = 0; i < tn; i++)
        cin>>ta[i];
    LinkList<int> A1(ta,tn),A2(ta,tn),A3(ta,tn);

    cout<<"�����뼯��B�ĳ��ȣ�";
    cin>>tn;
    cout<<"�밴˳����뼯��B��Ԫ�أ�";
    for (int i = 0; i < tn; i++)
        cin>>ta[i];
    LinkList<int> B1(ta,tn),B2(ta,tn),B3(ta,tn);
    //�ж����
    if (IsEqual(A1,B1) == 1)
        cout<<"A,B�������"<<endl;
    else cout<<"A,B���ϲ����"<<endl;
    //�󽻼�
    Interest(A1,B1);
    cout<<"A,B�Ľ����ǣ�"<<endl;B1.PrintList();
    //�󲢼�
    unionList(A2,B2);
    cout<<"A,B�Ĳ����ǣ�"<<endl;A2.PrintList();
	//��
    cout<<"A,B�Ĳ�ǣ�"<<endl;
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
