#include<iostream>  
#include"LinkList.cpp"  
using namespace std;

int main( )
{
	int m,r[100],f;
//����
	cout<<"�������������鳤��m��������100����";
	cin>>m;
	cout<<endl<<"����������Ԫ�أ�";
    for (int i = 0; i < m; i++)
		cin>>r[i];
  	LinkList<int> L(r, m),L2(r, m);
	L.PrintList( );                  
	try
  	{
		int p,da;
		cout<<"������������ݵ�λ�ã�";
		cin>>p;
		cout<<endl<<"���������ľ������ݣ�";
		cin>>da;
    	L.Insert(p,da);
   		cout<<endl<<"��λ��"<<p<<"��������"<<da<<"���Ϊ:"<<endl;
  		L.PrintList( );
	}
  	catch (int k)
  	{
  		cout<<"Insert error! i="<<k<<endl;
  	}
//����
	cout<<endl<<"������Ҫ���ҵ����ݣ�";
	cin>>f;
  	cout<<endl<<"����"<<f<<"��λ��Ϊ��"<<endl;
  	cout<<L.Locate(f)<<endl;
//ɾ��
 	cout<<endl<<"ɾ��ǰ����Ϊ��"<<endl;     
 	L.PrintList( );
  	try
 	{
		int p;
		cout<<endl<<"��������Ҫɾ�������ݵ�λ�ã�";
		cin>>p;
		L.Delete(p); 
  		cout<<endl<<"ɾ��λ��"<<p<<"�����ݺ�Ϊ��"<<endl;
  		L.PrintList( ); 		                  
  	}
  	catch (int k)
  	{
  		cout<<"Delete error! i="<<k<<endl;
  	}
	cout<<endl<<"���鳤��Ϊ��"<<endl<<L.Length()<<endl;  
	return 0;
}
