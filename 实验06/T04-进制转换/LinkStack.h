#ifndef SeqStack_H
#define SeqStack_H
//const int StackSize = 10;
template<class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};

template<class DataType>
class LinkStack
{
    public:
        LinkStack();
        LinkStack(int a,int k);
        ~LinkStack();
        void Push(DataType x);
        DataType Pop();
        DataType GetTop();
        int Empty();
    private:
        Node<DataType> *top;
};
#endif
