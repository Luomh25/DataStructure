#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Bitree.h"

int main()
{
    Bitree T;
    BiNode *root = T.getRoot();
    cout<<"����������������ǰ���������������������"<<endl;
    T.PreOrder(root);
    cout<<endl;
    cout<<"���������������������������������������"<<endl;
    T.InOrder(root);
    cout<<endl;
    cout<<"���������������������������������������"<<endl;
    T.PostOrder(root);
    cout<<endl;
    return 0;
}