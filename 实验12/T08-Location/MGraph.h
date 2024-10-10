#ifndef MGraph_H
#define MGraph_H
#include <string>
using namespace std;
int const MaxSize = 10;

class MGraph
{
    public:
        MGraph(string a[], int n, int e);
        ~MGraph();
        friend void Floyd(MGraph G);
    private:
        string vertex[MaxSize];
        int arc[MaxSize][MaxSize];
        int vertexNum, arcNum;
};

void Floyd(MGraph G);

#endif