#include <iostream>
#include <cstring>
#include <cstdio>
#include "SeqStack.cpp"
using namespace std;

int main()
{
    SeqStack<int> num1, num2;
    SeqStack<char> sign1, sign2;
    int lp;
    cout<<"������������ʽ����#��β��"<<endl;
    string pres, posts;
    cin>>pres;
    int l=pres.length();
    cout<<"��׺���ʽΪ��";
    for (int i = 0; i < l-1; i++)  cout<<pres[i];
    cout<<endl;
    cout<<"��׺���ʽΪ��";
    posts = pres;
    postfix(pres, num2, sign2, posts, lp);
    
    char post[100];
    for (int i = 0; i < lp; i++)  post[i] = posts[i];

    cout<<"���ݺ�����ʽ����һ�ö����ʾ��:"<<endl;
	Bitree T(post,lp);
	cout<<endl;
	cout<<"-----ǰ�����-----"<<endl; T.PreOrder();
	cout<<endl;
	cout<<"-----�������-----"<<endl; T.InOrder();	
	cout<<endl;
	cout<<"-----�������-----"<<endl; T.PostOrder();	
	cout<<endl;
    return 0; 
}