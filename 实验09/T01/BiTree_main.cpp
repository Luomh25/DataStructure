#include <iostream>
using namespace std;
#include "BiTree.h"

int main()
{
    BiTree T;
    cout<<endl;
    cout<<"������������ǰ�����������������"<<endl;
    T.PreOrder();
    cout<<endl;
    cout<<"�������������������������������"<<endl;
    T.InOrder();
    cout<<endl;
    cout<<"�������������������������������"<<endl;
    T.PostOrder();
    cout<<endl;
}
