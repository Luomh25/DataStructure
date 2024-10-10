#include <iostream>
using namespace std;
#include "MGraph.cpp"

int main()
{
	string ch[ ]={"A", "B", "C", "D", "E"};
	cout<<"enter the amount of point and edge:";
	int n, e;
	cin>>n>>e;
	MGraph G(ch, n, e);
	Floyd(G);
	return 0;
}