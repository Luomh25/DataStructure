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
    cout<<"请输入中序表达式，以#结尾："<<endl;
    string pres, posts;
    cin>>pres;
    int l=pres.length();
    cout<<"中缀表达式为：";
    for (int i = 0; i < l-1; i++)  cout<<pres[i];
    cout<<endl;
    cout<<"后缀表达式为：";
    posts = pres;
    postfix(pres, num2, sign2, posts, lp);
    
    char post[100];
    for (int i = 0; i < lp; i++)  post[i] = posts[i];

    cout<<"根据后序表达式建立一棵二叉表示树:"<<endl;
	Bitree T(post,lp);
	cout<<endl;
	cout<<"-----前序遍历-----"<<endl; T.PreOrder();
	cout<<endl;
	cout<<"-----中序遍历-----"<<endl; T.InOrder();	
	cout<<endl;
	cout<<"-----后序遍历-----"<<endl; T.PostOrder();	
	cout<<endl;
    return 0; 
}