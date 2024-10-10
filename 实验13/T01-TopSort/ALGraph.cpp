#include <iostream>
#include "ALGraph.h"
using namespace std;
extern int visited[];

template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
    ArcNode * s;
    int i, j, k;
    vertexNum = n;
    arcNum = e;
    for ( i = 0; i < vertexNum; i++)
    {
        adjlist[i].vertex = a[i];
        adjlist[i].firstedge = NULL;
        adjlist[i].in = 0;
    }
    for ( k = 0; k < arcNum; k++)
    {
        cout<<"请输入边的两个顶点的序号（保持序关系）：";
        cin>>i>>j;
        if (i == j)  break;
        s = new ArcNode;
        s -> adjvex = j;
        s -> next = adjlist[i].firstedge;
        adjlist[i].firstedge = s;
        adjlist[j].in++;
    }
}

template <class T>
ALGraph<T>::~ALGraph()
{
    ArcNode * p;
    for (int i = 0; i < vertexNum; i++)
    {
        p = adjlist[i].firstedge;
        while (p != NULL)
        {
            adjlist[i].firstedge = p -> next;
            delete p;
            p = adjlist[i].firstedge;
        }
    }
}

template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
    ArcNode * p = NULL;
    int j;
    cout<<adjlist[v].vertex;
    visited[v] = 1;
    p = adjlist[v].firstedge;
    while (p != NULL)
    {
        j = p -> adjvex;
        if (visited[j] == 0)  DFSTraverse(j);
        p = p -> next;
    }
}

template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
    int Q[MaxSize];
    int front = -1, rear = -1;
    ArcNode * p;
    cout<<adjlist[v].vertex;
    visited[v] = 1;
    Q[++rear] = v;
    while (front != rear)
    {
        v = Q[++front];
        p = adjlist[v].firstedge;
        while (p != NULL)
        {
            int j = p -> adjvex;
            if (visited[j] == 0)
            {
                cout<<adjlist[j].vertex;
                visited[j] = 1;
                Q[++rear] = j;
            }
            p = p -> next;
        }
    }
}

template <class DataType>
void TopSort(ALGraph<DataType> &G)
{
    int count = 0, top = -1;
	for (int i = 0; i < G.vertexNum; i++)
	{
		if (G.adjlist[i].in == 0)
		{
			G.adjlist[i].in = top;
			top = i;
		}
	}
	while (top != -1)
	{
		int j = top;
		top = G.adjlist[top].in;
		cout<<G.adjlist[j].vertex<<" ";
		count++;
		ArcNode * p = G.adjlist[j].firstedge;
		while (p != NULL)
		{
			int k = p -> adjvex;
			G.adjlist[k].in--;
			if (G.adjlist[k].in == 0)
			{
				G.adjlist[k].in = top;
				top = k;
			}
			p = p->next;
		}
	}
	if (count < G.vertexNum)  cout<<"有回路"<<endl;
}