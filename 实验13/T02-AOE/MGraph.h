#ifndef MGraph_H
#define MGraph_H

const int MaxSize = 10;
const int INF = 1000;
extern int visited[MaxSize];

template <class DataType>
class MGraph
{
    public:
        MGraph(DataType a[], int n, int e);
        ~MGraph();
        void DFSTraverse(int v);
        void BFSTraverse(int v);
        template <class T>
        friend int GetVL(MGraph<T> &G, int k, int vertexTop[], int vl[]);
        template <class T>
        friend int GetVE(MGraph<T> &G, int k, int vertexTop[], int ve[]);
        template <class T>
        friend void AOE(MGraph<T> &G);
    private:
        DataType vertex[MaxSize];
        int arc[MaxSize][MaxSize];
        int vertexNum, arcNum;
};

#endif