#ifndef CirQueue_H
#define CirQueue_H
const int QueueSize=100;

template <class T>
class CirQueue
{
    public:
        CirQueue();
        ~CirQueue(){};
        void EnQueue(T x);
        T DeQueue();
        T GetQueue();
        int Empty();
    private:
        T data[QueueSize];
        int front,rear;
};
#endif
