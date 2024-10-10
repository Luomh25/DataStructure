#include <iostream>
#include <string>
#include "MGraph.h"
using namespace std;

extern int visited[];

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
        cout<<"请输入边的两个顶点的序号及权值：";
        cin>>i>>j;
        cin>>arc[i][j];
    }
}

MGraph::~MGraph()
{
    //empty
}

void Dijkstra(MGraph G, int v)
{
    int n = G.vertexNum;
    int dist[n];
    string path[n];
    for (int i = 0; i < G.vertexNum; i++)
    {
        dist[i] = G.arc[v][i];
        if (dist[i] != 1000)  path[i] = G.vertex[v] + G.vertex[i];
        else path[i] = " ";
    }
    int num = 1;
    while(num < n)
    {
        int k = 0;
        while (dist[k] == 0)  k++;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] != 0 && dist[i] < dist[k]) 
                k = i;
        }
        cout<<G.vertex[v]<<"到"<<G.vertex[k]<<"的最短路径为："<<path[k]<<"，长度为"<<dist[k]<<endl;
        num++;
        for (int i = 0; i < n; i++)
            if (dist[i] > dist[k] + G.arc[k][i])
            {
                dist[i] = dist[k] + G.arc[k][i];
                path[i] = path[k] + G.vertex[i];
            }
        dist[k] = 0;
    }
}