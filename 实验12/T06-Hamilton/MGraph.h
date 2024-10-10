#ifndef MGraph_H
#define MGraph_H
#include <string>
using namespace std;
int const MaxSize = 10;

struct ShortEdge
{
    int lowcost;
    int adjvex;
};

class MGraph
{
    public:
        MGraph(string a[], int n, int e);
        ~MGraph();
        friend void Hamilton(MGraph &G, int v, int S[], int &count);
    private:
        string vertex[MaxSize];
        int arc[MaxSize][MaxSize];
        int vertexNum, arcNum;
};

void Hamilton(MGraph &G, int v, int S[], int &count);

#endif