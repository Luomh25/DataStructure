#include <iostream>
#include "MGraph.h"
using namespace std;

extern int visited[];
template <class T>
MGraph<T>::MGraph(T a[], int n, int e)
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
        arc[j][i] = 1;
    }
}

template <class T>
MGraph<T>::~MGraph()
{
    //empty
}

template <class T>
void MGraph<T>::DFSTraverse(int v)
{
    cout<<vertex[v];
    visited[v] = 1;
    for (int j = 0; j < vertexNum; j++)
        if (arc[v][j] == 1 && visited[j] == 0)
            DFSTraverse(j);
}

template <class T>
void MGraph<T>::BFSTraverse(int v)
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

template <class T>
void MGraph<T>::PrintMat()
{
    int i, j;
    cout<<"\n\nMartix Graph:"<<endl;
    for ( i = 0; i < vertexNum; i++)
    {
        for ( j = 0; j < vertexNum; j++)
        {
            cout<<setw(5)<<arc[i][j];
        }
        cout<<endl;
    }
}

template <class T>
void MGraph<T>::getMat(int (&mat)[MaxSize][MaxSize])
{
    for (int i = 0; i < MaxSize; i++)
    {
        for (int j = 0; j < MaxSize; j++)
        {
            mat[i][j] = arc[i][j];
        }
    }
}

template <class T>
int MGraph<T>::CountZero()
{
    int count = 0;
    for (int i = 0; i < vertexNum; i++)
    {
        bool tag = 0;
        for (int j = 0; j < vertexNum; j++)
        {
            if (arc[i][j] != 0)
            {
                tag = 1;
                break;
            }
        }
        if (!tag)  count++;
    }
    return count;
}

template <class T>
void MGraph<T>::DFS_nrc(int v)
{
    int top = -1;
    cout<<vertex[v];
    int visited[vertexNum] = {0};
    visited[v] = 1;
    int S[vertexNum] = {0};
    S[++top] = v;
    while (top != -1)
    {
        v = S[top];
		int j;
		for (j = 0; j < vertexNum; j++)
		{
			if (arc[v][j] == 1 && visited[j] == 0)
			{
				cout<<vertex[j];
				visited[j] = 1;
				S[++top] = j;
				break;
			}
        }
        if (j == vertexNum)  top--;
    }
}