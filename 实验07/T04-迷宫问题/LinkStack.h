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
	    LinkStack();                 //��ʼ��ջ
		~LinkStack();            	 //���
	    void Push(int x,int y,int d);//��Ԫ��x��ջ
	    Point Pop();                 //��ջ��Ԫ�ص���
	    Point GetTop();	             //ȡջ��Ԫ�أ�����ɾ����
		int Empty();            	 //�ж�ջ�Ƿ�Ϊ��
		friend void migong();
	private:
	    Node  *top;                  //ջ��ָ�룬ָʾջ��Ԫ���������е��±�
};
#endif
