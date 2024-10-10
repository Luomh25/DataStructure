#include <iostream>
#include "MGraph.cpp"
using namespace std;
int visited[MaxSize] = {0};

int main()
{
    char ch[] = {'A','B','C','D','E','F'};
    MGraph<char> MG(ch, 6, 6);
    for (int i = 0; i < MaxSize; i++)
        visited[i] = 0;
    cout<<"深度的优先遍历序列是：";
    MG.DFSTraverse(0);
    cout<<endl;
    for (int i = 0; i < MaxSize; i++)
        visited[i] = 0;
    cout<<"广度的优先遍历序列是：";
    MG.BFSTraverse(0);
    cout<<endl;
    return 0;
}
