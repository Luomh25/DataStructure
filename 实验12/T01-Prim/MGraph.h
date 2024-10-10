#ifndef MGraph_H
#define MGraph_H

const int MaxSize = 10;
extern int visited[MaxSize];

struct Candidate
{
	int adjvex;
	int lowcost;
};

int MinEdge(Candidate shortEdge[], int vertexNum);

class MGraph
{
    public:
        MGraph();
        ~MGraph();
        void Prim();
    private:
        int arc[MaxSize][MaxSize];
        int vertexNum, arcNum;
};

#endif
