#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Bitree.h"

int main()
{
    Bitree T;
    BiNode *root = T.getRoot();
    cout<<"！！！！！！！！念會演煽！！！！！！！！"<<endl;
    T.PreOrder(root);
    cout<<endl;
    cout<<"！！！！！！！！嶄會演煽！！！！！！！！"<<endl;
    T.InOrder(root);
    cout<<endl;
    cout<<"！！！！！！！！朔會演煽！！！！！！！！"<<endl;
    T.PostOrder(root);
    cout<<endl;
    return 0;
}