#include <iostream>
using namespace std;
#include "Bitree.cpp"

int main()
{	
	Bitree T;
	Bitree R;
	if (Like(T.getRoot(), R.getRoot()))  cout<<"similar"<<endl;
	else cout<<"not similar"<<endl;
	return 0;
}
