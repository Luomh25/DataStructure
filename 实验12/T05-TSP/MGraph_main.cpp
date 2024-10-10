#include <iostream>
using namespace std;
#include <string>
#include "MGraph.cpp"

int main()
{
	string ch[ ]={"A", "B", "C", "D", "E","F"};
	cout<<"输入顶点数：";
	int n;
	cin>>n;
	MGraph G(ch, n);
	cout<<"请输入源点："<<endl;
	string yd;
	cin>>yd;
	int v=yd[0]-ch[0][0];
	TSP(G, v);
	return 0;
}