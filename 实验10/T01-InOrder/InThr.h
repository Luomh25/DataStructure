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
        InThrBitree();                                  //���캯��������������������
        ~InThrBitree();                                 //�����������ͷŽ��洢�ռ�
        ThrNode<DataType> * Next(ThrNode<DataType> * p);//����p�ĺ��
        void InOrder();
    private:
        ThrNode<DataType> * root;
        void Release(ThrNode<DataType> *bt);
        void ThrBitree(ThrNode<DataType> * &bt, ThrNode<DataType> * &pre);
        ThrNode<DataType> * Creat(ThrNode<DataType> * bt);
};

#endif