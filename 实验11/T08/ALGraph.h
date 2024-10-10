#ifndef ALGraph_H
#define ALGraph_H
const int MaxSize = 10;

struct ArcNode
{
    int adjvex;
    ArcNode * next;
};

template <class T>
struct VertexNode
{
    T vertex;
    ArcNode * firstedge;
};

template <class T>
class ALGraph
{
    private:
        VertexNode<T> adjlist[MaxSize];
        int vertexNum, arcNum;
    public:
        ALGraph(T a[], int n, int e);
        ALGraph(T a[], int n, int e, int arc[MaxSize][MaxSize]);
        ~ALGraph();
        void DFSTraverse(int v);
        void BFSTraverse(int v);
        int CountZero();
        void List(VertexNode<T> (&Inv)[MaxSize]);
        bool Path_DFS(int x, int y);
        bool Path_BFS(int x, int y);
};

#endif