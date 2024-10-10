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
	    void Insert (int i, DataType x);//插入 
		int Locate (DataType x);		
		void PrintList();				//输出 		
		void Delete (int i);			//删除 		
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
	if (n> MaxSize) throw "参数非法";	
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
		throw "上溢";
	if(i< 1||i> length+1) 
		throw "位置异常";
	for (int j=length;j>=i;j--)
		data[j]= data[j-1];
	data[i-1]=x;
	length++;
}

template < class DataType>
void SeqList<DataType> ::Delete (int i)
{
	if(length==0) throw "下溢";
	if(i<1||i>length ) throw  "位置";	
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
	//下标为i的元素等于x,返回其序号i+1
	return 0;
	//退出循环,说明查找失败
}

template < class T>
void Union ( SeqList<T>& LA, SeqList<T>& LB ) 
{
	int n1 = LA.Length(), n2 = LB.Length();
    int i, k;
	T x;
    for ( i = 0; i < n2; i++ ) 
	{
        x = LB.data[i];  //在LB中取一元素
	    k = LA.Locate(x);//在LA中搜索它
	    if (k == 0)	     //若在LA中未找到插入它
	    { 
		   	LA.Insert(n1, x);  
			n1++; 
		}		  		 //插入到第n个表项位置
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
    	x = LA.data[i];  //在LA中取一元素
        k = LB.Locate(x);//在LB中搜索它	
	    if (k == 0) 	 //若在LB中未找到
        { 
			LA.Delete(i+1);  
			n1--; 
		}  				//在LA中删除它
	   else i++;                       
    }
 }

int main()
{
	int ta[1000],tn;
 	cout<<"请输入顺序表LA长度(不超过100)："<<endl;
	cin>>tn;
	cout<<"请逐个输入顺序表LA中的数字（整数）"<<endl;
	for(int i=0;i<tn;i++)
		cin>>ta[i]; 
	SeqList<int> A2(ta,tn);
	SeqList<int> A1(ta,tn);

	cout<<"请输入顺序表LB长度(不超过100)："<<endl;
	cin>>tn;
	cout<<"请逐个输入顺序表LB中的数字（整数）"<<endl;
	for(int i=0;i<tn;i++)
		cin>>ta[i]; 
	SeqList<int> B2(ta,tn);
	SeqList<int> B1(ta,tn);
	
	Union(A1,B1);
	Intersection(A2,B2); 
	cout<<"LA与LB的并为："<<endl;
	A1.PrintList();
	cout<<"LA与LB的交为："<<endl;
	A2.PrintList();
	return 0;
}