#ifndef Tree_H
#define Tree_H
const int Max=20;

struct TNode
{
    char data;
    TNode *firstchild,*rightsib;
};

//����������tree������ 
class Tree
{
    public:
        Tree();
        ~Tree();
        void PreOrder();
        void PostOrder();
    private:
        TNode *root;
        void Release(TNode *bt);
        void PreOrder(TNode *bt);
        void PostOrder(TNode *bt);
};

#endif
