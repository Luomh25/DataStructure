#include <iostream>
#include "MGraph.cpp"
using namespace std;
int main()
{
    string ch[]={"A", "B", "C", "D", "E","F", "G", "H", "I", "J"};
	cout<<"输入顶点数和边数：";
	int n, e;
	cin>>n>>e;
	MGraph G(ch, n, e);
	Floyd(G); 
	return 0;
}