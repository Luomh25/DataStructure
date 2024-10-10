#include <iostream>
#include "EdgeGraph.cpp"
using namespace std;

int main()
{
    EdgeGraph E;
    Initial(E);
    cout<<"最小生成树的边及其权值如下："<<endl;
    Kruskal(E);
    return 0;
}