#include <iostream>
#include "CirQueue.h"
//const int Maxsize=100;

template <class T>
CirQueue<T>::CirQueue()               //�����ն�
{
    Node<T>*s = new Node<T>;
    s -> next = NULL;
    front = rear = s;
}

template <class T>
CirQueue<T>::~CirQueue()              //���
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
void CirQueue<T>::EnQueue(T x)         //���
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
T CirQueue<T>::DeQueue()               //����
{
    if (rear == front) throw"����";
    else
    {
        Node<T>*s = rear -> next;
        if (s == rear) rear = NULL;
        else rear -> next = s -> next;
        delete s;
    }
}

template <class T>
T CirQueue<T>::GetQueue()              //ȡ���ס���ɾ��
{
    if (rear == front) throw"����";
    return front -> next -> data;
}

template <class T>
int CirQueue<T>::Empty()               //�пպ���
{
    if (rear == front) return 1;
    else return 0;
}
