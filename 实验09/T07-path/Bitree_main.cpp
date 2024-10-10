#include <iostream>
using namespace std;
#include "Bitree.cpp"

int main()
{	
	Bitree T;
	BiNode * root = T.getRoot();
	BiNode * test = T.getleftleaf(root);
	Path(root, test);
	return 0;
}
