#ifndef MGraph_H
#define MGraph_H
#include <string>
using namespace std;
extern int visited[10];

class MGraph
{
    public:
        MGraph(string a[]);
        ~MGraph();
        void Path();
    private:
        string vertex[10];
        int arc[10][10];
        int vertexNum, arcNum;
};

#endif