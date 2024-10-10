#include <iostream>
#include <iomanip>
using namespace std;
#include "ALGraph.cpp"
#include "MGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	char ch[]={'A','B','C','D','E','F','G'};
	MGraph<char> MG(ch, 8, 6); // ���������
	int i = MG.CountZero();
	cout<<endl<<"����Ϊ0�ĵ�ĸ���: "<<i<<endl;
	MG.PrintMat();
	int mat[MaxSize][MaxSize] = {0};
	MG.getMat(mat);
	ALGraph<char> ALG(ch, 8, 6, mat);  // ���տα�P152
	int j = ALG.CountZero();
	cout<<endl<<"����Ϊ0�ĵ�ĸ���: "<<j<<endl;
	return 0;
} 