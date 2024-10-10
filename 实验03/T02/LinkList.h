#ifndef LinkList_H
#define LinkList_H

template <class DataType>
class Node
{
    public:
		DataType data;
    	Node<DataType> *next;  
};

template <class DataType>
class LinkList
{
	public:
		LinkList( );                     
		LinkList(DataType a[ ], int n);     
		~LinkList( );                    
		int Locate(DataType x);           
		void Insert(int i, DataType x);      
		DataType Delete(int i);           
		void PrintList( );	
		LinkList(LinkList<DataType> &L);      
		LinkList<DataType> &  operator=(LinkList<DataType> &L);  
		Node<DataType> *getfirst();  
	    int Length( );                  
		int Increase( );                   
		void Reverse( );                 
		void Insert(DataType x);        
		void Purge();                      
	
	private:
		Node<DataType> *first;                    
};
#endif