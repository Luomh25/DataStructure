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
    void InitList();  //初始化 
    int Length();    //求链表长度 
    int Search(T x);  //寻找元素x所在结点位置 
    int Locate(int i); //寻找第i个结点的元素 
    bool Append(T x);   //在表尾追加一个新结点 
    bool Insert(int i,T x); //在第i个结点插入值为x的元素 
    bool Remove(int i);   //删除第i个结点 
    bool isEmpty();  //判断链表空否 
    void PrintList();  //输出链表中所有元素 
private:
    Node<T> elem[Maxsize];  
    int avail;   //当前可支配空间首地址 
};
#endif
