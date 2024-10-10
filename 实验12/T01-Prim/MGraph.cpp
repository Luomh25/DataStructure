#include <iostream>
#include "MGraph.h"
using namespace std;

extern int visited[];

MGraph::MGraph()
{
    cout<<"输入顶点数和边数：";
	cin>>vertexNum>>arcNum;
	int i, j, m;
	for (i=0; i<vertexNum; i++)
        for (j=0; j<vertexNum; j++)
			arc[i][j]=1000;//以 1000当做无穷 
	for (int k=0; k<arcNum; k++)
	{
		cout<<"请输入边的两个顶点的序号和其权值：";
		cin>>i;
		cin>>j;
		cin>>m;
		arc[i][j]=m; arc[j][i]=m;
    }
}

MGraph::~MGraph()
{
    //empty
}

void MGraph::Prim()
{
    int k;
    Candidate shortEdge[MaxSize];
    for (int i = 0; i < vertexNum; i++)
    {
        shortEdge[i].lowcost = arc[0][i];
        shortEdge[i].adjvex = 0;
    }
    shortEdge[0].lowcost = 0;
    for (int i = 0; i < vertexNum-1; i++)
    {
        k = MinEdge(shortEdge, vertexNum);
        cout<<"("<<k<<", "<<shortEdge[k].adjvex<<") "<<shortEdge[k].lowcost<<endl;
        shortEdge[k].lowcost = 0;
        for (int j = 0; j < vertexNum-1; j++)
        {
            if (arc[k][j] < shortEdge[j].lowcost)
            {
                shortEdge[j].lowcost = arc[k][j];
                shortEdge[j].adjvex = k;
            }
        }
    }
}

int MinEdge(Candidate shortEdge[], int vertexNum)
{
    int min = 1000;
    int k;
    for (int i = 0; i < vertexNum; i++)
    {
        if (shortEdge[i].lowcost != 0 && shortEdge[i].lowcost < min)
        {
            min = shortEdge[i].lowcost;
            k = i;
        }
    }
    return k;
}