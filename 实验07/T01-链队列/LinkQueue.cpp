#include <iostream>
#include "LinkQueue.h"
//const int Maxsize=100;

template <class T>
LinkQueue<T>::LinkQueue()               //建立空队
{
    Node<T>*s = new Node<T>;
    s -> next = NULL;
    front = rear = s;
}

template <class T>
LinkQueue<T>::~LinkQueue()              //清除
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
void LinkQueue<T>::EnQueue(T x)         //入队
{
    Node<T>*s = new Node<T>;
    s -> data = x;
    s -> next = NULL;
    rear -> next = s;
    rear = s;
}

template <class T>
T LinkQueue<T>::DeQueue()               //出队
{
    if (rear == front) throw"下溢";
    Node<T> *p = front -> next;
    front -> next = p -> next;
    if (p -> next == NULL) rear = front;
    T x = p -> data; 
    delete p;                           //在队列中删除队首元素
    return x;                           //输出出队元素
}

template <class T>
T LinkQueue<T>::GetQueue()              //取队首、不删除
{
    if (rear == front) throw"下溢";
    return front -> next -> data;
}

template <class T>
int LinkQueue<T>::Empty()               //判空函数
{
    if (rear == front) return 1;
    else return 0;
}