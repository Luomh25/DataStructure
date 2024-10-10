#include <iostream>
using namespace std;
#include "LinkQueue.cpp"

int main()
{
    LinkQueue<int> Q;
    cout<<"Q.Empty = "<<Q.Empty()<<endl;
    cout<<"Q.EnQueue(10),Q.EnQueue(15)"<<endl;
    Q.EnQueue(10);
    Q.EnQueue(15);
    cout<<"Q.GetQueue = "<<Q.GetQueue()<<endl;
    cout<<"Q.DeQueue = "<<Q.DeQueue()<<endl;
    cout<<"Q.GetQueue = "<<Q.GetQueue()<<endl;
    cout<<"Q.Empty = "<<Q.Empty()<<endl;
    return 0;
}