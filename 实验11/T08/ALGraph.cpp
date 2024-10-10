#include <iostream>
#include <iomanip>
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
    }
    for ( k = 0; k < arcNum; k++)
    {
        cout<<"请输入边的两个顶点的序号：";
        cin>>i>>j;
        s = new ArcNode;
        s -> adjvex = j;
        s -> next = adjlist[i].firstedge;
        adjlist[i].firstedge = s;
    }
}

template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e, int arc[MaxSize][MaxSize])
{
    arcNum = e;
    vertexNum = n;
    for (int i = 0; i < vertexNum; i++)
    {
        VertexNode<T> tempvertex;
        tempvertex.vertex = a[i];
        tempvertex.firstedge = NULL;
        adjlist[i] = tempvertex;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i && arc[i][j] != 0)
            {
                ArcNode * s = new ArcNode;
                s -> adjvex = j;
                s -> next = adjlist[i].firstedge;
                adjlist[i].firstedge = s;
            }
        }
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

template <class T>
int ALGraph<T>::CountZero()
{
    int count = 0;
    ArcNode * p;
    for (int i = 0; i < vertexNum; i++)
    {
        p = adjlist[i].firstedge;
        if (!p)  count++;
    }
    return count;
}

template <class T>
void ALGraph<T>::List(VertexNode<T> (&Inv)[MaxSize])
{
    for (int i = 0; i < vertexNum; i++)
    {
        Inv[i].firstedge = NULL;
        Inv[i].vertex = adjlist[i].vertex;
    }
    ArcNode * p = new ArcNode;
    int j;
    for (int i = 0; i < vertexNum; i++)
    {
        p = adjlist[i].firstedge;
        while (p != NULL)
        {
            j = p -> adjvex;
            ArcNode * s = new ArcNode;
            s -> adjvex = i;
            s -> next = Inv[j].firstedge;
            Inv[j].firstedge = s;
            p = p -> next;
        }
    }
}

template <class T>
bool ALGraph<T>::Path_DFS(int x, int y)
{
    int v = x;
    int top, j;
    ArcNode * p;
    for (int i = 0; i < vertexNum; i++)
    {
        visited[0] = 0;
    }
    int S[MaxSize];
    top = -1;
    visited[v] = 1;
    S[++top] = v;
    while (top != -1)
    {
        v = S[top];
        p = adjlist[v].firstedge;
        while (p != NULL)
        {
            j = p -> adjvex;
            if (visited[j] == 0)
            {
                cout<<adjlist[j].vertex<<" ";
                if (j == y)  return true;
                visited[j] == 1;
                S[++top] = j;
                break;
            }
            p = p -> next;
        }
        if (p == NULL)  top--;
    }
    return false;
}

template <class T>
bool ALGraph<T>::Path_BFS(int x, int y)
{
    int v = x;
    int front, rear, j;
    ArcNode * p;
    for (int i = 0; i < vertexNum; i++)
    {
        visited[0] = 0;
    }
    int Q[MaxSize];
    front = rear = -1;
    visited[v] = 1;
    Q[++rear] = v;
    while (front != rear)
    {
        v = Q[++front];
        p = adjlist[v].firstedge;
        while (p != NULL)
        {
            j = p -> adjvex;
            if (visited[j] == 0)
            {
                cout<<adjlist[j].vertex<<" ";
                if (j == y)  return true;
                visited[j] == 1;
                Q[++rear] = j;
            }
            p = p -> next;
        }
    }
    return false;
}

void ifs(bool flag)
{
	if (flag)  cout<<"has path"<<endl;
	else  cout<<"no path"<<endl;
}