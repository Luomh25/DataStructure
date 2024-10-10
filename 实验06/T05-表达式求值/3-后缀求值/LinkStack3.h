#ifndef LinkStack_H
#define LinkStack_H

struct Node
{
		char data;
    	Node *next;  
};

class LinkStack
{
	public:
		LinkStack();
		~LinkStack();
		void Push(char x);
		char Pop();
		char GetTop();
	private:
		Node *top;
};
int Operate(char a,char thera,char b);
char Sufix();
#endif
