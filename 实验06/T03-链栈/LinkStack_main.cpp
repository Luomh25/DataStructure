#include <iostream>         //�������������
using namespace std;
#include "LinkStack.cpp"       //�����Ա�����ļ�

int main( )
{    
    LinkStack<int> S;      //����ģ�����ʵ��
	try
	{		
		if (S.Empty()==1)
			cout<<"ջΪ��"<<endl;
		else
	        cout<<"ջ�ǿ�"<<endl;
	    cout<<"��15��10��5��1ִ����ջ����"<<endl;
		S.Push(15);
		S.Push(10);   
		S.Push(5); 
		S.Push(1); 
		cout<<"ջ��Ԫ��Ϊ:"<<S.GetTop( )<<endl;  
		cout<<"ִ��һ�γ�ջ����"<<endl;
		S.Pop( );          //ִ�г�ջ����
	    cout<<"ջ��Ԫ��Ϊ:"<<S.GetTop( )<<endl;	
		cout<<"ִ��һ�γ�ջ����"<<endl;
		S.Pop( );          //ִ�г�ջ����
	    cout<<"ջ��Ԫ��Ϊ:"<<S.GetTop( )<<endl;	
		cout<<"ִ��һ�γ�ջ����"<<endl;
		S.Pop( );          //ִ�г�ջ����
	    cout<<"ջ��Ԫ��Ϊ:"<<S.GetTop( )<<endl;
	    cout<<"ִ��һ�γ�ջ����"<<endl;
		S.Pop( );          //ִ�г�ջ����    
	    cout<<"ִ��һ�γ�ջ����"<<endl;
	    S.Pop( );  
	}
	catch (const char *s)
	{  
		cout<<s<<"\n";
	}
	return 0;
}