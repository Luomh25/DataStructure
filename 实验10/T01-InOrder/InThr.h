#ifndef INTHR_H
#define INTHR_H

enum flag{Child, Thread};

template <typename T1>
struct ThrNode
{
    T1 data;
    ThrNode<T1> * lchild, * rchild;
    flag ltag, rtag;
};

template <class DataType>
class InThrBitree
{
    public:
        InThrBitree();                                  //构造函数，建立中序线索链表
        ~InThrBitree();                                 //析构函数，释放结点存储空间
        ThrNode<DataType> * Next(ThrNode<DataType> * p);//查找p的后继
        void InOrder();
    private:
        ThrNode<DataType> * root;
        void Release(ThrNode<DataType> *bt);
        void ThrBitree(ThrNode<DataType> * &bt, ThrNode<DataType> * &pre);
        ThrNode<DataType> * Creat(ThrNode<DataType> * bt);
};

#endif