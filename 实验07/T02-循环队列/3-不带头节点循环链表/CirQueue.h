#ifndef CirQueue_H
#define CirQueue_H
const int Maxsize=100;
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class CirQueue
{
    public:
        CirQueue();
        ~CirQueue();
        void EnQueue(T x);
        T DeQueue();
        T GetQueue();
        int Empty();
    private:
        Node<T> *front,*rear;
};
#endif