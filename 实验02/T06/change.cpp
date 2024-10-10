#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MaxSize=100;
template <class DataType>
class SeqList
{
public:
    SeqList ();
    SeqList (DataType a[],int n);
    ~SeqList(){;}
    int Length(){return length;}
    void Inverse();
    void PrintList();
private:
    DataType data[MaxSize];
    int length;
};

template <class DataType>
SeqList<DataType>::SeqList()
{
    length=0;
}

template <class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
    if (n>MaxSize) throw "�����Ƿ�";
    for(int i=0;i<n;i++)
        data[i]=a[i];
    length=n;
}

template <class DataType>
void SeqList<DataType>::PrintList()
{
    for (int i = 0; i < length; i++)
        cout<<data[i]<<" ";
    cout<<endl;
}

template <class DataType>
void SeqList<DataType>::Inverse()
{
    int i=0,j=length-1;
    DataType t;
    while (i<j)
    {
        t=data[i];
        data[i]=data[j];
        data[j]=t;
        i++;
        j--;
    }
}

int main()
{
    int Ta[1000],Tn;
    cout<<"������˳���ĳ��ȣ�������100����"<<endl;
    cin>>Tn;
    cout<<"���������˳����е����֣���������"<<endl;
    for (int i = 0; i < Tn; i++)
        cin>>Ta[i];

    SeqList<int> A(Ta,Tn);
    A.Inverse();
    cout<<"���ú��˳���Ϊ��"<<endl;
    A.PrintList();
    return 0;
}