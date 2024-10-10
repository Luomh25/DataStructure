#include <iostream>
#include <iomanip>
using namespace std;
#include "ALGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	char ch[]={'A','B','C','D'};
	ALGraph<char> ALG(ch, 4, 4);
	bool flag;
	flag = ALG.Path_BFS(2,0); ifs(flag);
	flag = ALG.Path_DFS(2,0); ifs(flag);
	flag = ALG.Path_BFS(2,1); ifs(flag);
	flag = ALG.Path_DFS(2,1); ifs(flag);
	flag = ALG.Path_BFS(1,3); ifs(flag);
	flag = ALG.Path_DFS(1,3); ifs(flag);
	return 0;
} 