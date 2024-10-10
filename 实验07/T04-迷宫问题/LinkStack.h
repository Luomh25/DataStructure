#ifndef SEQSTACK_H
#define SEQSTACK_H

struct Point
{
	int x;
	int y;
	int d;
};

struct Node
{
    Point p;
    Node *next;  
};

class LinkStack
{
	public:
	    LinkStack();                 //初始化栈
		~LinkStack();            	 //清空
	    void Push(int x,int y,int d);//将元素x入栈
	    Point Pop();                 //将栈顶元素弹出
	    Point GetTop();	             //取栈顶元素（并不删除）
		int Empty();            	 //判断栈是否为空
		friend void migong();
	private:
	    Node  *top;                  //栈顶指针，指示栈顶元素在数组中的下标
};
#endif
