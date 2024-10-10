#ifndef LinkStack2_H
#define LinkStack2_H
//const int StackSize = 10;
template <typename T>
struct Node
{
	T data;
	Node<T> *next;
};

template <typename T>
class LinkStack
{    
    public:
        LinkStack( );
        ~LinkStack( );            
        void Push(T x);
        T Pop( ); 
        T GetTop( );
        int Empty( );
        void makeEmpty();
    private:
        Node<T> *top; 
};
int icp(const char a);
int isp(const char a);
void Run();
#endif
