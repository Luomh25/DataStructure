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
    private:
        BiNode *root;
        char pin[MaxSize];
        char pre[MaxSize];
    public:
        Bitree();
        Bitree(BiNode *bt);
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
        BiNode * interface();
        BiNode * create(BiNode * &root, int i1, int i2, int k);
        int pos(char, char[], int, int);
};

#endif
