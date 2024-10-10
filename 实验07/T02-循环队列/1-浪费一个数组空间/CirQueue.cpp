#include <iostream>
#include "CirQueue.h"

template <class T>
CirQueue<T>::CirQueue()               //�����ն�
{
    rear = front = QueueSize-1;
}

template <class T>
void CirQueue<T>::EnQueue(T x)         //���
{
    if ((rear+1)%QueueSize == front) throw "����";
    rear = (rear+1)%QueueSize;
    data[rear] = x;
}

template <class T>
T CirQueue<T>::DeQueue()               //����
{
    if (rear == front) throw"����";
    front = (front+1)%QueueSize;
    return data[front];
}

template <class T>
T CirQueue<T>::GetQueue()              //ȡ���ס���ɾ��
{
    if (rear == front) throw"����";
    int i = (front+1)%QueueSize;
    return data[i];
}

template <class T>
int CirQueue<T>::Empty()               //�пպ���
{
    if (rear == front) return 1;
    else return 0;
}