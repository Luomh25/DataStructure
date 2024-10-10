#include <iostream>
#include "MGraph.cpp"
using namespace std;

int visited[MaxSize] = {0};

int main()
{
    MGraph MG;
    cout<<"最小生成树的各边权值如下："<<endl;
    MG.Prim();
    return 0;
}