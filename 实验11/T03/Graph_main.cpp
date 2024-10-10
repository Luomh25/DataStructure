#include <iostream>
#include <iomanip>
using namespace std;
#include "ALGraph.cpp"
#include "MGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	char ch[]={'A','B','C','D','E'};
	MGraph<char> MG(ch, 6, 6);
	MG.PrintMat();
	int mat[MaxSize][MaxSize] = {0};
	MG.getMat(mat);
	ALGraph<char> ALG(ch, 6, 6, mat);
	return 0;
} 