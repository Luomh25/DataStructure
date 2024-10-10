#include <iostream>
#include <string>
#include <iomanip>
#include "MGraph.h"
using namespace std;

MGraph::MGraph(string a[])
{
    int i, j, k;
    vertexNum = arcNum = 10;
    for ( i = 0; i < 10; i++)
        vertex[i] = a[i];
    for ( i = 0; i < 10; i++)
        for ( j = 0; j < 10; j++)
            arc[i][j] = 0;
    //邻接表
    arc[0][4] = arc[4][0] = 1;
	arc[1][6] = arc[6][1] = 1;
	arc[1][7] = arc[7][1] = 1;
	arc[2][6] = arc[6][2] = 1;
	arc[2][8] = arc[8][2] = 1;
	arc[3][4] = arc[4][3] = 1;
	arc[3][7] = arc[7][3] = 1;
	arc[3][8] = arc[8][3] = 1;
	arc[5][6] = arc[6][5] = 1;
	arc[5][9] = arc[9][5] = 1;
}

MGraph::~MGraph()
{
    //empty
}

void MGraph::Path()
{
    int S[10];
    int top = -1;
    visited[0] = 1;
    S[++top] = 0;
    int yes = 0;
    int t;
    while (top != -1 && yes == 0)
    {
        int p = 0;
        int i = S[top];
        while (arc[i][p] == 0)  p++;
        while (p < 10 && yes == 0)
        {
            t = p;
            if (t == 9)
            {
                S[++top] = t;
                yes = 1;
            }
            else if (visited[t] == 0)
            {
                visited[t] = 1;
                S[++top] = t;
                i = t;
                p = 0;
                while (arc[t][p] == 0)  p++;
            }
            else
            {
                p++;
                while (arc[i][p] == 0 && p < 10)  p++;
            }
        }
        if (p == 10)  top--;
    }
    string str;
    int count, p, bank;
    for (int i = 0; i < top; i++)
    {
        count = 0;
        p = 10;
        if (vertex[ S[i+1] ][0] == '1')  bank = 1;
        else bank = 0;

        for (int j = 1; j < 4; j++)
            if (vertex[ S[i+1] ][j] != vertex[ S[i] ][j])
            {
                p = j;
                count++;
                break;
            }
        if (p == 1) str = "wolf";
        else if (p == 2) str = "cabbage";
        else if (p == 3) str = "goat";
        if (count == 0)
        {
            if (bank == 1) cout<<"farmer -> B"<<endl;
            else cout<<"farmar -> A"<<endl;
        }
        else
        {
            if (bank == 1) cout<<"farmer + "<<str<<" -> B"<<endl;
            else cout<<"farmer + "<<str<<" -> A"<<endl;
        }
    }
}