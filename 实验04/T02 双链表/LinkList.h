#ifndef LinkList_H
#define LinkList_H

template <class DataType>
struct Node
{
    DataType data;
	Node<DataType> *next,*prior;  
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
		void Delete(int i);           
		void PrintList( );	
	    int Length( );                                     
	private:
		Node<DataType> *first;                    
};
#endif