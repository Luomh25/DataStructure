#ifndef LinkList_H
#define LinkList_H
template <class DataType>
struct Node
{
      DataType data;
      Node<DataType> *next;  
};
template <class DataType>
class LinkList
{
	public:
		LinkList( );                    
		LinkList(int a[],int n);      
		~LinkList( );
		int Length( );
		void Delete(DataType x); 
		void PrintList();   
		int Locate(DataType x); 
		void Insert(DataType x);           
		template <class T> 
		friend int IsEqual(LinkList<T> &A, LinkList<T> &B);  
		template <class T> 
		friend void Interest(LinkList<T> &A, LinkList<T> &B);  
		template <typename T> 
		friend void unionList(LinkList<T> &A, LinkList<T> &B); 
		template <typename T> 
		friend void Difference(LinkList<T> &A, LinkList<T> &B); 
	private:
		Node<DataType> *first;                    
};
#endif
