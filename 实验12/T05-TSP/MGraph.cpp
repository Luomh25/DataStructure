#include <iostream>
#include <string>
#include <iomanip>
#include "MGraph.h"
using namespace std;

extern int visited[];

MGraph::MGraph(string a[], int n)
{
    int i, j, k;
    vertexNum = n, arcNum = n*(n - 1);
    for ( i = 0; i < vertexNum; i++)
        vertex[i] = a[i];
    for ( i = 0; i < vertexNum; i++)
        for ( j = 0; j < vertexNum; j++)
            arc[i][j] = 1000;
    for ( i = 0; i < vertexNum; i++)
        arc[i][i] = 0;
    for ( k = 0; k < arcNum; k++)
    {
        cout<<"请输入边的两个顶点的序号及权值：";
        cin>>i>>j;
        cin>>arc[i][j];
    }
}

MGraph::~MGraph()
{
    //empty
}

void TSP(MGraph &G, int v)
{
    int p0 = v;
    string path = G.vertex[v];
    int length = 0;
    G.arc[v][v] = 1;
    int k;
    for (int i = 1; i < G.vertexNum; i++)
    {
        k = FindMin(G, v);
        path = path + G.vertex[k];
        length = length + G.arc[v][k];
        G.arc[k][k] = 1;
        v = k;
    }
    path = path + G.vertex[p0];
    length = length + G.arc[v][p0];
    cout<<G.vertex[p0]<<"走完所有顶点并回到自身的最短路径为："<<path<<"，长度为"<<length<<endl;
}

int FindMin(MGraph &G, int v)
{
    int k = 0;
    while (G.arc[k][k] == 1 || k == v)  k++;
    for (int i = k; i < G.vertexNum; i++)
    {
        if (G.arc[i][i] != 1 && i != v &&G.arc[v][i] < G.arc[v][k])
            k = i;
    }
    return k;
}