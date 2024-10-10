#include<iostream>  
#include"LinkList.cpp"  
using namespace std;

int main( )
{
	int r[5]={1, 9, 3, 4, 5};
  	LinkList<int> L(r, 5),L2(r, 5);
  
	if(L.Increase()==1)
		cout<<"The LinkList is incresing."<<endl;          
  	else
		cout<<"The LinkList is not incresing."<<endl;          
 	
	cout<<"Before inserting£º"<<endl;
	L.PrintList( );                  
	try
  	{
    	L.Insert(2, 3);
  	//	L.Insert(22, 3);
   		cout<<"After inserting 3£º"<<endl;
  		L.PrintList( );  		
	}
  	catch (int k )
  	{
  		cout<<"Insert error! i="<<k<<endl;
  	} 
  	
  	cout<<"After inserting 5£º"<<endl;
  	L.PrintList( );                  
  	cout<<"The position of 5 is:"<<endl;
  	cout<<L.Locate(5)<<endl;       
 	cout<<"Before deleting the first element of the LinkList£º"<<endl;     
 	L.PrintList( );                 
  	try
 	{
  		L.Delete(1);
  	//	L.Delete(66);
	  	cout<<"After deleting£º"<<endl;     
  		L.PrintList( );  
  	}
  	catch (int k)
  	{
  		cout<<"Delete error! i="<<k<<endl;
  	}
	
	cout<<"The length is:"<<endl<<L.Length()<<endl;  
  	L2.Reverse();
	cout<<"The reversed LinkList is:"<<endl;
	L2.PrintList();  
	
	cout<<"Before deleting the same elements£º"<<endl;
	int r1[9]={1, 2, 4,4,4,5, 5, 6,6};
  	LinkList<int> L1(r1, 9);
  	L1.PrintList(); 
	L1.Purge();
	cout<<"After deleting the same elements£º"<<endl;
  	L1.PrintList();
	L1.Insert(3);
	cout<<"Insert 3 to build an orderly LinkList£º"<<endl;
	L1.PrintList();
	return 0;
}