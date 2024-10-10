#include <iostream>
#include "EdgeGraph.h"
using namespace std;

void Initial(EdgeGraph &E)          //构造图
{
    cout<<"输入顶点数和边数：";
    cin>>E.vertexNum>>E.edgNum;
    for (int i = 0; i < E.edgNum; i++)
    {
        cout<<"输入边上两个顶点和权值（权值从小到大输入）：";
        cin>>E.edge[i].from>>E.edge[i].to>>E.edge[i].weight;
    }
}

void Kruskal(EdgeGraph &E)
{
    int parent[E.vertexNum];
    for (int i = 0; i < E.vertexNum; i++)
        parent[i] = -1;
    int num = 0, vex1, vex2;
    for (int i = 0; i < E.edgNum; i++)
    {
        vex1 = FindRoot(parent, E.edge[i].from);
        vex2 = FindRoot(parent, E.edge[i].to);
        if (vex1 != vex2)
        {
            cout<<"("<<E.edge[i].from<<", "<<E.edge[i].to<<") "<<E.edge[i].weight<<endl;
            parent[vex2] = vex1;
            num++;
            if (num == E.vertexNum - 1)  return;
        }
    }
}

int FindRoot(int parent[], int v)
{
    while (parent[v] > -1)  v = parent[v];
    return v;
}