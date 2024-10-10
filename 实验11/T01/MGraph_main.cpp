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
    cout<<"��ȵ����ȱ��������ǣ�";
    MG.DFSTraverse(0);
    cout<<endl;
    for (int i = 0; i < MaxSize; i++)
        visited[i] = 0;
    cout<<"��ȵ����ȱ��������ǣ�";
    MG.BFSTraverse(0);
    cout<<endl;
    return 0;
}
