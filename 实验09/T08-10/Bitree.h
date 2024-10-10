#ifndef Bitree_H
#define Bitree_H
const int MaxSize=100;
struct BiNode
{
	char data;       
	BiNode *lchild, *rchild;
};

class Bitree
{
public:
	Bitree();
    Bitree(BiNode * bt);
	~Bitree();
    BiNode * getRoot();
    BiNode * Creat(BiNode *bt);
    void isEmpty();
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LeverOrder();
	void Release(BiNode *bt);
	void PreOrder(BiNode *bt);
	void InOrder(BiNode *bt);
	void PostOrder(BiNode *bt);
	void countLeaves(BiNode * root, int &num);    
	int countLeaves();
	int countNode();
private:
	BiNode * root;
    void countNode(BiNode * root, int &num);
};
#endif