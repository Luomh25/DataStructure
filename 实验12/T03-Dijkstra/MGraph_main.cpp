#include <iostream>
#include "MGraph.cpp"
using namespace std;

int main()
{
    string ch[] = {"A","B","C","D","E"};
    cout<<"输入顶点数和边数：";
    int n, e;
    cin>>n>>e;
    MGraph G(ch, n, e);
    cout<<"请输入原点："<<endl;
    string yd;
    cin>>yd;
    int v = yd[0] - ch[0][0];
    Dijkstra(G, v);
    return 0;
}