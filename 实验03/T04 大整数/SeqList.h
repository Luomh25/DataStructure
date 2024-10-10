const int MaxSize = 1000;         
template <class DataType>     
class SeqList
{
	public:
		SeqList( ) ;           
		SeqList(DataType a[ ], int n);      
		~SeqList( ) ;              
		int Length( ) ;    
		void PrintList( );                     
		void negtive(); //用于设置结果的正负 
	   	//判断函数：用于判断A，B大小
		template <class T>
		friend	int BigInt_Judge(SeqList<T> A, SeqList<T> B); 		   
		//退位函数：推掉减法或乘法高位多于的0 
 		template <class T>
 		friend void BigInt_Abdicate(int l,SeqList<T> &C);		
		//加法函数 
		template <class T> 
		friend void BigInt_ADD(SeqList<T> A, SeqList<T> B,SeqList<T> &C);  
	    //减法函数
		template <class T>  
	    friend void BigInt_SUB(SeqList<T> A, SeqList<T> B,SeqList<T> &C); 
	    //绝对值C=A-B函数，默认A>=B 
		template <class T>  
	    friend void BigInt_ABS(SeqList<T> A, SeqList<T> B,SeqList<T> &C); 	    
	   	//乘法函数
	    template <class T> 
	    friend void BigInt_MUL(SeqList<T> A, SeqList<T> B,SeqList<T> &C);  
		//除法函数
		template <class T>
		friend void BigInt_DIV(SeqList<T> A, SeqList<T> B,SeqList<T> &C,SeqList<T> &D);
	private:
		DataType data[MaxSize];             //存放数据元素的数组
	    int length;                         //线性表的长度
	    int sign;							//符号
};