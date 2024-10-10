#include <iostream>
#include <iomanip>
using namespace std;
#include "ALGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	char ch[]={'A','B','C','D'};
	ALGraph<char> ALG(ch, 4, 4);
	VertexNode<char> Inv[MaxSize];
	ALG.List(Inv);
	return 0;
} 