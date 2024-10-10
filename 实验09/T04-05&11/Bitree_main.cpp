#include <iostream>
#include "Bitree.cpp"
using namespace std;

int main()
{
    Bitree T;
    T.isEmpty();
    T.interface();
    T.isEmpty();
	cout<<"------preorder------ "<<endl;T.PreOrder();
	cout<<endl;
	cout<<"------inorder------ "<<endl;T.InOrder();
	cout<<endl;
	cout<<"------postorder------ "<<endl;T.PostOrder();
	cout<<endl;
	cout<<"------leverorder------ "<<endl;T.LeverOrder();
	cout<<endl;

    cout<<"------COPY------ "<<endl;
    BiNode * Troot = new BiNode;
    Troot = CopyTree(T.getRoot());
    Bitree Tc(Troot);
    cout<<"------preorder------ "<<endl;Tc.PreOrder();
	cout<<endl;
	cout<<"------inorder------ "<<endl;Tc.InOrder();
	cout<<endl;
	cout<<"------postorder------ "<<endl;Tc.PostOrder();
	cout<<endl;
	cout<<"------leverorder------ "<<endl;Tc.LeverOrder();
	cout<<endl;

	cout<<"------REVERSE------ "<<endl;
	PostOrder(T.getRoot());
    return 0;  
}