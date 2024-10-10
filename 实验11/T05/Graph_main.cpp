#include <iostream>
#include <iomanip>
using namespace std;
#include "ALGraph.cpp"
#include "MGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	char ch[]={'A','B','C','D','E','F','G'};
	MGraph<char> MG(ch, 8, 6); // 多出两个点
	int i = MG.CountZero();
	cout<<endl<<"出度为0的点的个数: "<<i<<endl;
	MG.PrintMat();
	int mat[MaxSize][MaxSize] = {0};
	MG.getMat(mat);
	ALGraph<char> ALG(ch, 8, 6, mat);  // 对照课本P152
	int j = ALG.CountZero();
	cout<<endl<<"出度为0的点的个数: "<<j<<endl;
	return 0;
} 