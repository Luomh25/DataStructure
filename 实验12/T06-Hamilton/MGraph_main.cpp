#include <iostream>
#include <string>
using namespace std;
#include "MGraph.cpp"

int visited[MaxSize] = { 0 };

int main() {
	string ch[4] = { "A","B","C","D" };
	MGraph G(ch, 4, 5);
	int count = 0; int *S = new int[4];
	cout << "从A点出发，";
	Hamilton(G, 0, S, count);
	count = 0; 
	for (int i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "从B点出发，";
	Hamilton(G, 1, S, count);
	return 0;
}