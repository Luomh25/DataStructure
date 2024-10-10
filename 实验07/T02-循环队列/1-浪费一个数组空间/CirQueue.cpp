#include <iostream>
#include "CirQueue.h"

template <class T>
CirQueue<T>::CirQueue()               //建立空队
{
    rear = front = QueueSize-1;
}

template <class T>
void CirQueue<T>::EnQueue(T x)         //入队
{
    if ((rear+1)%QueueSize == front) throw "上溢";
    rear = (rear+1)%QueueSize;
    data[rear] = x;
}

template <class T>
T CirQueue<T>::DeQueue()               //出队
{
    if (rear == front) throw"下溢";
    front = (front+1)%QueueSize;
    return data[front];
}

template <class T>
T CirQueue<T>::GetQueue()              //取队首、不删除
{
    if (rear == front) throw"下溢";
    int i = (front+1)%QueueSize;
    return data[i];
}

template <class T>
int CirQueue<T>::Empty()               //判空函数
{
    if (rear == front) return 1;
    else return 0;
}