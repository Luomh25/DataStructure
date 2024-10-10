#ifndef LinkQueue_H
#define LinkQueue_H

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkQueue
{
    private:
        Node<T> *front, *rear;
    public:
        LinkQueue();
        ~LinkQueue();
        void EnQueue(T x);
        T DeQueue();
        T GetQueue();
        T GetQueuetail();
        int Empty();
};

#endif