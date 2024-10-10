#ifndef StaticList_H
#define StaticList_H
const int Maxsize=100;
template <class T>
struct Node
{
    T data;
    int link;
};
template<class T>
class StaticList
{
public:
    void InitList();  //��ʼ�� 
    int Length();    //�������� 
    int Search(T x);  //Ѱ��Ԫ��x���ڽ��λ�� 
    int Locate(int i); //Ѱ�ҵ�i������Ԫ�� 
    bool Append(T x);   //�ڱ�β׷��һ���½�� 
    bool Insert(int i,T x); //�ڵ�i��������ֵΪx��Ԫ�� 
    bool Remove(int i);   //ɾ����i����� 
    bool isEmpty();  //�ж�����շ� 
    void PrintList();  //�������������Ԫ�� 
private:
    Node<T> elem[Maxsize];  
    int avail;   //��ǰ��֧��ռ��׵�ַ 
};
#endif
