#include <iostream>
#include "LinkQueue.h"
//const int Maxsize=100;

template <class T>
LinkQueue<T>::LinkQueue()               //�����ն�
{
    Node<T>*s = new Node<T>;
    s -> next = NULL;
    front = rear = s;
}

template <class T>
LinkQueue<T>::~LinkQueue()              //���
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
void LinkQueue<T>::EnQueue(T x)         //���
{
    Node<T>*s = new Node<T>;
    s -> data = x;
    s -> next = NULL;
    rear -> next = s;
    rear = s;
}

template <class T>
T LinkQueue<T>::DeQueue()               //����
{
    if (rear == front) throw"����";
    Node<T> *p = front -> next;
    front -> next = p -> next;
    if (p -> next == NULL) rear = front;
    T x = p -> data; 
    delete p;                           //�ڶ�����ɾ������Ԫ��
    return x;                           //�������Ԫ��
}

template <class T>
T LinkQueue<T>::GetQueue()              //ȡ���ס���ɾ��
{
    if (rear == front) throw"����";
    return front -> next -> data;
}

template <class T>
int LinkQueue<T>::Empty()               //�пպ���
{
    if (rear == front) return 1;
    else return 0;
}