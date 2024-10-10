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
    for ( i = 0; i < n; i++)
        vertex[i] = a[i];
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            arc[i][j] = 1000;
    for ( i = 0; i < n; i++)
        arc[i][i] = 0;
    for ( k = 0; k < arcNum; k++)
    {
        cout<<"please enter the 2 points and weight:";
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = G.arc[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)   
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    int E[n];
    for (int k = 0; k < n; k++)
    {
        E[k] = dist[0][k];
        for (int j = 0; j < n; j++)
            if (dist[j][k] > E[k])  E[k] = dist[j][k];
    }
    cout<<"Point  Eccentricity"<<endl;
	for(int i = 0; i < n; i++)
		cout<<setw(3)<<G.vertex[i]<<setw(10)<<E[i]<<endl;
	int p = 0;
	for(int j = 1; j < n; j++)
		if(E[j] < E[p]) p=j;
	cout<<"The location of the hospital is "<<G.vertex[p]<<endl;
}