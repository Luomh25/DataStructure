#include <iostream>
#include <string>
#include <iomanip>
#include "MGraph.h"
using namespace std;

extern int visited[MaxSize];
extern int count;
extern char S[MaxSize];

MGraph::MGraph(string a[], int n, int e)
{
    int i, j, k;
    vertexNum = n, arcNum = e;
    for ( i = 0; i < vertexNum; i++)
        vertex[i] = a[i];
    for ( i = 0; i < vertexNum; i++)
        for ( j = 0; j < vertexNum; j++)
            arc[i][j] = 0;
    for ( k = 0; k < arcNum; k++)
    {
        cout<<"请输入边的两个顶点的序号：";
        cin>>i>>j;
        arc[i][j] = 1;
    }
}

MGraph::~MGraph()
{
    //empty
}

void Hamilton(MGraph &G, int v, int S[], int &count)
{
	int j = 0;
	visited[v] = 1;
    S[count++] = v;
	if (count == G.vertexNum)
    {
		for (int i = 0; i < G.vertexNum; i++)
			cout << G.vertex[S[i]] << ' ';
		cout << endl;
		return;
	}
	for (j = 0; j < G.vertexNum; j++) {
		if (G.arc[v][j] != 0 && visited[j] == 0)
			Hamilton(G, j, S, count);
		if (count == G.vertexNum) return;
	}
	if (j == G.vertexNum)
    {
		visited[v] = 0;
        count--;
	}
	if (count == 0)
		cout << "no path" << endl;
}