#ifndef LinkQueue_H
#define LinkQueue_H
const int Maxsize=100;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class LinkQueue
{
    public:
        LinkQueue();
        ~LinkQueue();
        void EnQueue(T x);
        T DeQueue();
        T GetQueue();
        int Empty();
    private:
        Node<T> *front,*rear;
};
#endif