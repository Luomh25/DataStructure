#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MaxSize=100;
template <class DataType>
class SeqList
{
	public: 
		SeqList () ; 
		SeqList (DataType a[], int n);
		~SeqList(){ ;}
		int Length() {return length;}
	    void Insert (int i, DataType x);//���� 
		int Locate (DataType x);		
		void PrintList();				//��� 		
		void Delete (int i);			//ɾ�� 		
		template <class T>
		friend void Union (SeqList<T>& LA, SeqList<T>& LB );
		template <class T>
	   	friend void Intersection( SeqList<T> & LA, SeqList<T> & LB ); 
	private:
		DataType data[MaxSize];
		int length;
};

template <class DataType>
SeqList<DataType> ::SeqList() 
{
	length=0;
}

template <class DataType>
SeqList<DataType> ::SeqList(DataType a[],int n)
{
	if (n> MaxSize) throw "�����Ƿ�";	
	for(int i=0;i<n;i++)
		data[i]=a[i];
	length= n;
}

template < class DataType>
void SeqList< DataType> ::PrintList()
{
	for(int i=0; i< length;i++ )
		cout<<data[i]<<" ";	
	cout<<endl; 
}

template <class DataType> 
void SeqList<DataType> ::Insert (int i,DataType x) 
{
	if (length>=MaxSize) 
		throw "����";
	if(i< 1||i> length+1) 
		throw "λ���쳣";
	for (int j=length;j>=i;j--)
		data[j]= data[j-1];
	data[i-1]=x;
	length++;
}

template < class DataType>
void SeqList<DataType> ::Delete (int i)
{
	if(length==0) throw "����";
	if(i<1||i>length ) throw  "λ��";	
	for(int j=i;j<length;j++)
	{
		data[j-1]=data[j];
	}
	length--;
}

template < class DataType>
int SeqList< DataType> ::Locate (DataType x)
{
	for (int i= 0;i< length;i++)
	if (data[i]==x)
		return i+1;
	//�±�Ϊi��Ԫ�ص���x,���������i+1
	return 0;
	//�˳�ѭ��,˵������ʧ��
}

template < class T>
void Union ( SeqList<T>& LA, SeqList<T>& LB ) 
{
	int n1 = LA.Length(), n2 = LB.Length();
    int i, k;
	T x;
    for ( i = 0; i < n2; i++ ) 
	{
        x = LB.data[i];  //��LB��ȡһԪ��
	    k = LA.Locate(x);//��LA��������
	    if (k == 0)	     //����LA��δ�ҵ�������
	    { 
		   	LA.Insert(n1, x);  
			n1++; 
		}		  		 //���뵽��n������λ��
	}
}

template < class T>
void Intersection ( SeqList<T> & LA,     SeqList<T> & LB ) 
{
    int n1 = LA.Length ( );
    int k, i = 0;
    T x;
	while ( i < n1 ) 
	{
    	x = LA.data[i];  //��LA��ȡһԪ��
        k = LB.Locate(x);//��LB��������	
	    if (k == 0) 	 //����LB��δ�ҵ�
        { 
			LA.Delete(i+1);  
			n1--; 
		}  				//��LA��ɾ����
	   else i++;                       
    }
 }

int main()
{
	int ta[1000],tn;
 	cout<<"������˳���LA����(������100)��"<<endl;
	cin>>tn;
	cout<<"���������˳���LA�е����֣�������"<<endl;
	for(int i=0;i<tn;i++)
		cin>>ta[i]; 
	SeqList<int> A2(ta,tn);
	SeqList<int> A1(ta,tn);

	cout<<"������˳���LB����(������100)��"<<endl;
	cin>>tn;
	cout<<"���������˳���LB�е����֣�������"<<endl;
	for(int i=0;i<tn;i++)
		cin>>ta[i]; 
	SeqList<int> B2(ta,tn);
	SeqList<int> B1(ta,tn);
	
	Union(A1,B1);
	Intersection(A2,B2); 
	cout<<"LA��LB�Ĳ�Ϊ��"<<endl;
	A1.PrintList();
	cout<<"LA��LB�Ľ�Ϊ��"<<endl;
	A2.PrintList();
	return 0;
}