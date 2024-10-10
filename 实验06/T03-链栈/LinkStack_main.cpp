#include <iostream>         //引用输入输出流
using namespace std;
#include "LinkStack.cpp"       //引入成员函数文件

int main( )
{    
    LinkStack<int> S;      //创建模板类的实例
	try
	{		
		if (S.Empty()==1)
			cout<<"栈为空"<<endl;
		else
	        cout<<"栈非空"<<endl;
	    cout<<"对15、10、5、1执行入栈操作"<<endl;
		S.Push(15);
		S.Push(10);   
		S.Push(5); 
		S.Push(1); 
		cout<<"栈顶元素为:"<<S.GetTop( )<<endl;  
		cout<<"执行一次出栈操作"<<endl;
		S.Pop( );          //执行出栈操作
	    cout<<"栈顶元素为:"<<S.GetTop( )<<endl;	
		cout<<"执行一次出栈操作"<<endl;
		S.Pop( );          //执行出栈操作
	    cout<<"栈顶元素为:"<<S.GetTop( )<<endl;	
		cout<<"执行一次出栈操作"<<endl;
		S.Pop( );          //执行出栈操作
	    cout<<"栈顶元素为:"<<S.GetTop( )<<endl;
	    cout<<"执行一次出栈操作"<<endl;
		S.Pop( );          //执行出栈操作    
	    cout<<"执行一次出栈操作"<<endl;
	    S.Pop( );  
	}
	catch (const char *s)
	{  
		cout<<s<<"\n";
	}
	return 0;
}