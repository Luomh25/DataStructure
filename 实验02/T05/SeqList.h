#ifndef SeqList_H
#define SeqList_H
const int MaxSize=10;  
class SeqList
{
public:
   SeqList( ){length=0;}       //�޲ι��캯��������һ���ձ�
   SeqList(int a[ ], int n);   //�вι��캯��
   ~SeqList( ){ }              //��������Ϊ�� 
   void Insert(int i, int x);  //�����Ա��е�i��λ�ò���ֵΪx��Ԫ��
   int Delete(int i);          //ɾ�����Ա�ĵ�i��Ԫ��
   int Locate(int x);          //��ֵ���ң������Ա���ֵΪx��Ԫ�����
   void PrintList( );          //�������Ա���������������Ԫ��
   int Length( );              //�����߱�ĳ���
   int Get(int i);             //��λ���ң������Ա��в��ҵ�i��Ԫ��

private:
   int data[MaxSize];          //�������Ԫ�ص�����
   int length;                 //���Ա�ĳ���
};
#endif

