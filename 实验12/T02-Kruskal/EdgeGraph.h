#ifndef EdgeGraph_H
#define EdgeGraph_H

const int MaxSize = 10;
const int MaxEdge = 100;
extern int visited[MaxSize];

struct EdgeType
{
	int from, to;
	int weight;
};

struct EdgeGraph
{
    EdgeType edge[MaxEdge];
    int vertexNum, edgNum;
};


void Initial(EdgeGraph &E);
void Kruskal(EdgeGraph &E);
int FindRoot(int parent[], int v);

#endif
