#ifndef Bitree_H
#define Bitree_H
const int MaxSize=100;
struct BiNode   //二叉树的结点结构
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
	void info(BiNode * bt);
	void del(char x);
private:
	BiNode * root;
	void Delete(BiNode * root, char x, BiNode * &p);
};
#endif
