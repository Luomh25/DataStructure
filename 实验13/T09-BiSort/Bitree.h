#ifndef Bitree_H
#define Bitree_H
const int Max = 100;
const int Len = 10;

struct BiNode
{
	int data;
	BiNode *lchild, *rchild;
};

class Bitree
{
public:
	Bitree(int a[], int n);				  // 建立一棵二叉排序树
	~Bitree();							  // 析构函数
	void Insert(int k);						  // 插入数值
	void InsertBST(BiNode *&root, BiNode *s); // 插入节点
	void DeleteBST(BiNode *p, BiNode *f);	  // 删除f的左孩子p
	BiNode *Search(int k);					  // 搜索数值
	BiNode *SearchBST(BiNode *root, int k);
	BiNode *getRoot();
	void PreOrder();
	void InOrder();
	void PostOrder();
	BiNode *Ancestor(int k1, int k2);
	BiNode *AncestorBST(BiNode *A, BiNode *B, BiNode *root);
	int Level(int k);
	int LevelBST(BiNode *root, BiNode *p);
	int SortBiTree();
	int SortBiTreeBST(BiNode *root);
	
private:
	BiNode *root;
	BiNode *Creat(BiNode *bt);
	void Release(BiNode *bt); // 封装的释放函数
	void PreOrder(BiNode *bt);
	void InOrder(BiNode *bt);
	void PostOrder(BiNode *bt);
};

#endif