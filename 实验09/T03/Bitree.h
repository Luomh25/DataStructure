#ifndef Bitree_H
#define Bitree_H
const int MaxSize=20;

struct BiNode
{
    char data;
    BiNode *lchild,*rchild;
};

struct element
{
    BiNode * ptr;
    int flag;
};


//以下是树类tree的声明 
class Bitree
{
    public:
        Bitree();
        ~Bitree();
        void PreOrder();
        void PostOrder();
        void LeverOrder();
        BiNode *getRoot();
        void Release(BiNode *bt);
        void PreOrder(BiNode *bt);
        void InOrder(BiNode *bt);
        void PostOrder(BiNode *bt);
    private:
        BiNode * root;
        BiNode * Creat(BiNode *bt);
        //void Release(BiNode *bt);
};

#endif
