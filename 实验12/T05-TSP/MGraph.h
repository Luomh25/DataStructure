#ifndef MGraph_H
#define MGraph_H
#include <string>
using namespace std;
int const MaxSize = 10;

class MGraph
{
    public:
        MGraph(string a[], int n);
        ~MGraph();
        friend void TSP(MGraph &G, int v);
        friend int FindMin(MGraph &G, int v);
    private:
        string vertex[MaxSize];
        int arc[MaxSize][MaxSize];
        int vertexNum, arcNum;
};

void TSP(MGraph &G, int v);
int FindMin(MGraph &G, int v);

#endif