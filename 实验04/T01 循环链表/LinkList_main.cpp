#include<iostream>  
#include"LinkList.cpp"  
using namespace std;

int main( )
{
	int m,r[100],f;
//插入
	cout<<"请输入插入的数组长度m（不超过100）：";
	cin>>m;
	cout<<endl<<"请依次输入元素：";
    for (int i = 0; i < m; i++)
		cin>>r[i];
  	LinkList<int> L(r, m),L2(r, m);
	L.PrintList( );                  
	try
  	{
		int p,da;
		cout<<"请输入插入数据的位置：";
		cin>>p;
		cout<<endl<<"请输入插入的具体数据：";
		cin>>da;
    	L.Insert(p,da);
   		cout<<endl<<"在位置"<<p<<"插入数据"<<da<<"结果为:"<<endl;
  		L.PrintList( );
	}
  	catch (int k)
  	{
  		cout<<"Insert error! i="<<k<<endl;
  	}
//查找
	cout<<endl<<"请输入要查找的数据：";
	cin>>f;
  	cout<<endl<<"数据"<<f<<"的位置为："<<endl;
  	cout<<L.Locate(f)<<endl;
//删除
 	cout<<endl<<"删除前数据为："<<endl;     
 	L.PrintList( );
  	try
 	{
		int p;
		cout<<endl<<"请输入想要删除的数据的位置：";
		cin>>p;
		L.Delete(p); 
  		cout<<endl<<"删除位置"<<p<<"的数据后为："<<endl;
  		L.PrintList( ); 		                  
  	}
  	catch (int k)
  	{
  		cout<<"Delete error! i="<<k<<endl;
  	}
	cout<<endl<<"数组长度为："<<endl<<L.Length()<<endl;  
	return 0;
}
