#ifndef SeqStack_H
#define SeqStack_H
const int StackSize = 10;
template<class DataType>
class SeqStack
{
    private:
        DataType data[StackSize];
        int top;
    public:
        SeqStack();
        ~SeqStack(){}
        void Push(DataType x);
        DataType Pop();
        DataType GetTop();
        int Empty();
};
#endif