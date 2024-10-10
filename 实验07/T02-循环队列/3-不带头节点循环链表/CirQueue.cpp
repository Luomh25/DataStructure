#include <iostream>
#include "CirQueue.h"
//const int Maxsize=100;

template <class T>
CirQueue<T>::CirQueue()               //建立空队
{
    Node<T>*s = new Node<T>;
    s -> next = NULL;
    front = rear = s;
}

template <class T>
CirQueue<T>::~CirQueue()              //清除
{
    Node<T>*p = NULL;
    while (front != NULL)
    {
        p = front ->next;
        delete front;
        front = p;
    }
}

template <class T>
void CirQueue<T>::EnQueue(T x)         //入队
{
    Node<T>*s = new Node<T>;
    s -> data = x;
    if (rear == NULL)
    {
        rear = s;
        rear -> next = s;
    }
    else
    {
        s -> next = rear -> next;
        rear -> next = s;
        rear = s;
    }
}

template <class T>
T CirQueue<T>::DeQueue()               //出队
{
    if (rear == front) throw"下溢";
    else
    {
        Node<T>*s = rear -> next;
        if (s == rear) rear = NULL;
        else rear -> next = s -> next;
        delete s;
    }
}

template <class T>
T CirQueue<T>::GetQueue()              //取队首、不删除
{
    if (rear == front) throw"下溢";
    return front -> next -> data;
}

template <class T>
int CirQueue<T>::Empty()               //判空函数
{
    if (rear == front) return 1;
    else return 0;
}
