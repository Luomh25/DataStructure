#include <iostream>
#include"ALGraph.cpp"
using namespace std;
int visited[MaxSize] = {0};

int main()
{
    char ch[] = {'A','B','C','D','E'};
    int i;
    ALGraph<char> ALG(ch, 5, 7);
    for (int i = 0; i < MaxSize; i++)  visited[i] = 0;
    cout<<"������ȱ��������ǣ�";
    ALG.DFSTraverse(0);
    cout<<endl;
    for (int i = 0; i < MaxSize; i++)  visited[i] = 0;
    cout<<"������ȱ��������ǣ�";
    ALG.BFSTraverse(0);
    cout<<endl;
    return 0;
}
