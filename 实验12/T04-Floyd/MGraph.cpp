#include <iostream>
#include <string>
#include <iomanip>
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

void Floyd(MGraph G)
{
    int n = G.vertexNum;
    int dist[n][n];
    string path[n][n];
    //int i, j;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = G.arc[i][j];
            if (dist[i][j] != 1000)  path[i][j] = G.vertex[i] + G.vertex[j];
            else path[i][j] = " ";
        }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)   
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k] + path[k][j].substr(1);
                }
    //输出
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(i != j)
            {
				if(dist[i][j] != 1000) 
					cout<<G.vertex[i]<<"到"<<G.vertex[j]<<"的最短路径为："<<setw(4)<<path[i][j]<<"，长度为"<<dist[i][j]<<endl;
				else 
					cout<<G.vertex[i]<<"到"<<G.vertex[j]<<"没有路径"<<endl;
			}
		}
}