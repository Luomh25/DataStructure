#ifndef MGraph_H
#define MGraph_H
//const int MaxSize = 10;

template <class T>
class MGraph
{
    private:
        T vertex[MaxSize];
        int arc[MaxSize][MaxSize];
        int vertexNum, arcNum;
    public:
        MGraph(T a[], int n, int e);
        ~MGraph();
        void DFSTraverse(int v);
        void BFSTraverse(int v);
        void PrintMat();
        void getMat(int (&mat)[MaxSize][MaxSize]);
};

#endif