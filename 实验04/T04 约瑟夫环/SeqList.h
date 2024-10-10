#ifndef SeqList_H
#define SeqList_H
const int MaxSize = 1000;         
template <class DataType>     
class SeqList
{
	public:
		SeqList( ) ;           
		SeqList(int n);      
		~SeqList( ) ;              
		void Joseph(int m);
		                   
	private:
		DataType data[MaxSize];          
	    int length;                   
};
#endif
