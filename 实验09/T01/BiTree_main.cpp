#include <iostream>
using namespace std;
#include "BiTree.h"

int main()
{
    BiTree T;
    cout<<endl;
    cout<<"！！！！！！念會演煽！！！！！！"<<endl;
    T.PreOrder();
    cout<<endl;
    cout<<"！！！！！！嶄會演煽！！！！！！"<<endl;
    T.InOrder();
    cout<<endl;
    cout<<"！！！！！！朔會演煽！！！！！！"<<endl;
    T.PostOrder();
    cout<<endl;
}
