#include <iostream>
#include <iomanip>
using namespace std;
#include "MGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	char ch[]={'A','B','C','D','E'};
	MGraph<char> MG(ch, 6, 6); //多出两个点
	MG.DFS_nrc(1);
	cout<<endl;
	MG.DFSTraverse(1);
	MG.PrintMat();
	return 0;
}