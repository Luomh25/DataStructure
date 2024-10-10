#ifndef LinkStack_H
#define LinkStack_H
//const int StackSize = 10;
struct Node
{
	char data;
	Node *next;
};
class LinkStack
{    
    public:
        LinkStack( );
        ~LinkStack( );            
        void Push(char x);
        char Pop( ); 
        char GetTop( );
        int Empty( );
    private:
        Node *top; 
};
bool InOP(char c);
int getpriority(char a);
char Preceded(char a,char b);
int Operate(char a,char thera,char b);
char com();
#endif
