#include <iostream>
#include "MGraph.h"
using namespace std;

extern int visited[];

template <class DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	int i, j, m;
    vertexNum = n;
    arcNum = e;
    for ( i = 0; i < vertexNum; i++)
        vertex[i] = a[i];
	for ( i = 0; i < vertexNum; i++)
        for (j = 0; j < vertexNum; j++)
			arc[i][j] = 0;
	for (int k = 0; k < arcNum; k++)
	{
		cout<<"请输入边的两个顶点的序号和其权值：";
		cin>>i;
		cin>>j;
		cin>>m;
		arc[i][j] = m;
    }
}

template <class DataType>
MGraph<DataType>::~MGraph()
{
    //empty
}

template <class DataType>
void MGraph<DataType>::DFSTraverse(int v)
{
	cout<<vertex[v];
	visited[v] = 1;
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] == 1 && visited[j] == 0)
			DFSTraverse(j);
	}
}

template <class DataType>
void MGraph<DataType>::BFSTraverse(int v)
{
	int Q[MaxSize];
	int front = -1, rear = -1;
	cout<<vertex[v];
	visited[v] = 1;
	Q[++rear] = v;
	while (front != rear)
	{
		v = Q[++front];
		for (int j = 0; j < vertexNum; j++)
			if (arc[v][j] == 1 && visited[j] == 0)
			{
				cout<<vertex[j];
				visited[j] = 1;
				Q[++rear] = j;
			}
	}
}

//计算最早发生时间
template <class T>
int GetVE(MGraph<T> &G, int k, int vertexTop[], int ve[])
{
    int max = -1, i;
    for ( i = 0; i < G.vertexNum; i++)
    {
        if (G.arc[i][k])
        {
            if (ve[vertexTop[i]] + G.arc[i][k] > max)
                max = ve[vertexTop[i]] + G.arc[i][k];
        }
    }
    if (max == -1)  return 0;
    else  return max;
}

//计算最迟发生时间
template <class T>
int GetVL(MGraph<T> &G, int k, int vertexTop[], int vl[])
{
    int min = INF, i;
    for ( i = 0; i < G.vertexNum; i++)
    {
        if (G.arc[k][i])
        {
            if (vl[vertexTop[i]] - G.arc[k][i] < min)
                min = vl[vertexTop[i]] - G.arc[k][i];    
        }
    }
    return min;
}

template <class T>
void AOE(MGraph<T> &G)
{
    int vertexTop[G.vertexNum];
    int S1[G.vertexNum], S2[G.vertexNum];
    int ve[G.vertexNum], vl[G.vertexNum];
    int ee[G.vertexNum][G.vertexNum] = {-1};
    int el[G.vertexNum][G.vertexNum] = {-1};
    int i, j, count = 0, top1 = -1, top2 = -1;
    int in[G.vertexNum] = {0};
    for ( j = 0; j < G.vertexNum; j++)
        for ( i = 0; i < G.vertexNum; i++)
            if (G.arc[i][j])  in[j]++;
    for ( i = 0; i < G.vertexNum; i++)
        if (!in[i])  S1[++top1] = i;
    while (top1 != -1)
    {
        int tmp = S1[top1--];
		vertexTop[tmp] = count;
		ve[count] = GetVE(G, tmp, vertexTop, ve);
		count++;
		S2[++top2] = tmp;
        for ( j = 0; j < G.vertexNum; j++)
        {
            if (G.arc[tmp][j])
            {
                in[j]--;
                if (!in[j])  S1[++top1] = j;
            }
        }
    }
    if (count < G.vertexNum)
	{
		cout<<"有回路"<<endl;
		return;
	}
	count--;
	int temp = S2[top2--];
	vl[count] = ve[count];
	while (top2 != -1)
	{
		count--;
		int tmp = S2[top2--];
		vl[count] = GetVL(G, tmp, vertexTop, vl);
	}
	// 计算ee
	for (i = 0; i < G.vertexNum; i++)
		for (j = 0; j < G.vertexNum; j++)
		{
			if (G.arc[i][j]) 
                ee[i][j] = ve[vertexTop[i]];
		}
	// 计算el
	cout << "关键活动有:" << endl;
	for (i = 0; i < G.vertexNum; i++)
		for (j = 0; j < G.vertexNum; j++)
			if (G.arc[i][j])
			{
				el[i][j] = vl[vertexTop[j]] - G.arc[i][j];
				if (el[i][j] == ee[i][j])
				{
					cout << G.vertex[i] << " -> " << G.vertex[j] << endl;
				}
			}
}