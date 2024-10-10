#ifndef LinkList_H
#define LinkList_H

struct Node
{
	double coef;
	int exp;
	Node *next;
};

class LinkList
{  
	public:
		LinkList();
		LinkList(double a[],int b[],int n);
		~LinkList();//Îö¹¹ 
		void PrintList();
		friend void Add(LinkList &A,LinkList &B);
	private:
   		Node *first;
};

#endif
