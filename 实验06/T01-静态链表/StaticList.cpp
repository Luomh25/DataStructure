#include<iostream>
using namespace std;
#include"StaticList.h"
template <class T>
void StaticList<T>::InitList()
{
    elem[0].link=-1;
    avail=1;
    for(int i=1;i<Maxsize;i++)
    {
        elem[i].link=i+1;
        elem[Maxsize-1].link=-1;
    }
}
template <class T>
int StaticList<T>::Length()
{
    int p=elem[0].link;
    int count=0;
    while(p!=-1)
    {
       p=elem[p].link;
       count++;
    }
    return count;
}
template <class T>
int StaticList<T>::Search(T x)
{
    int p=elem[0].link;
    while(p!=-1)
    {
        if(elem[p].data==x)
        break;
        else p=elem[p].link;
    }
    return p;
}
template <class T>
int StaticList<T>::Locate(int i)
{
    if(i<0) return -1;
    if(i==0)  return 0;
    int j=1;
    int p=elem[0].link;
    while(p!=-1&&j<i)
    {
        p=elem[p].link;
        j++;
    }
    return elem[p].data;
}
template <class T>
bool StaticList<T>::Append(T x)
{
    if(avail==-1)  return false;
    int q=avail;
    avail=elem[avail].link;
    elem[q].data=x;
    elem[q].link=-1;
    int p=0;
    while(elem[p].link!=-1)
    p=elem[p].link;
    elem[p].link=q;
    return true;
}
template <class T>
bool StaticList<T>::Insert(int i,T x)
{
    if(avail==-1)  return false;
    if(i<1||i>Maxsize)  throw"位置";
    else
    {
        int j=1;
        int p=elem[0].link;
        while(p!=-1&&j<i-1)
        {
          p=elem[p].link;
          j++;
        }
        if(p==-1)  throw"位置";
        else
        { 
		int s=avail;
        avail=elem[avail].link;
        elem[s].data=x;
        elem[s].link=elem[p].link;
        elem[p].link=s;
        } 
    }
    return true;

}
template <class T>
bool StaticList<T>::Remove(int i)
{
    if(avail==-1)  return false;
    if(i<1||i>Maxsize)  throw"位置";
    else
    {
        int j=1;
        int p=elem[0].link;
        while(p!=-1&&j<i-1)
        {
          p=elem[p].link;
          j++;
        }
        if(p==-1||elem[p].link==-1)  throw"位置";
        else
        { 
        int q=elem[p].link;
        elem[p].link=elem[q].link;
        elem[q].link=avail;
        avail=q;
        } 
    }
    return true;
}
template <class T>
bool StaticList<T>::isEmpty()
{
    if(elem[0].link==-1)  return true;
    else return false;
}
template <class T>
void StaticList<T>::PrintList()
{
    int p=elem[0].link;
    while(p!=-1)
    {
        cout<<elem[p].data<<" ";
        p=elem[p].link;
    }
    cout<<endl;
}
