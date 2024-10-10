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
		void negtive(); //�������ý�������� 
	   	//�жϺ����������ж�A��B��С
		template <class T>
		friend	int BigInt_Judge(SeqList<T> A, SeqList<T> B); 		   
		//��λ�������Ƶ�������˷���λ���ڵ�0 
 		template <class T>
 		friend void BigInt_Abdicate(int l,SeqList<T> &C);		
		//�ӷ����� 
		template <class T> 
		friend void BigInt_ADD(SeqList<T> A, SeqList<T> B,SeqList<T> &C);  
	    //��������
		template <class T>  
	    friend void BigInt_SUB(SeqList<T> A, SeqList<T> B,SeqList<T> &C); 
	    //����ֵC=A-B������Ĭ��A>=B 
		template <class T>  
	    friend void BigInt_ABS(SeqList<T> A, SeqList<T> B,SeqList<T> &C); 	    
	   	//�˷�����
	    template <class T> 
	    friend void BigInt_MUL(SeqList<T> A, SeqList<T> B,SeqList<T> &C);  
		//��������
		template <class T>
		friend void BigInt_DIV(SeqList<T> A, SeqList<T> B,SeqList<T> &C,SeqList<T> &D);
	private:
		DataType data[MaxSize];             //�������Ԫ�ص�����
	    int length;                         //���Ա�ĳ���
	    int sign;							//����
};