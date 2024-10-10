#include <iostream>
#include <string.h>
using namespace std;
#include "MGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	string ch[] = {"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8"};
	MGraph<string> MG(ch, 9, 11);
	AOE(MG);
	return 0;
}