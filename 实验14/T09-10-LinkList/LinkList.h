#ifndef LinkList_H
#define LinkList_H

struct Node
{
    int data;
	Node * next;  
};

class LinkList
{
	public:
		LinkList();                     
		LinkList(int a[], int n);     
		~LinkList();                    
		void PrintList();	
	    Node * getfirst();
		friend void StraightSort(LinkList &A);
		friend void SelectSort(LinkList &A);
	private:
		Node * first;
};
#endif
