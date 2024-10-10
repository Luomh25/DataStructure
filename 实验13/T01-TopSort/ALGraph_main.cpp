#include <iostream>
#include"ALGraph.cpp"
using namespace std;
int visited[MaxSize] = {0};

int main()
{
    string ch[] = {"A", "B", "C", "D", "E", "F"};
    int i;
    ALGraph<string> ALG(ch, 6, 9);
    for (int i = 0; i < MaxSize; i++)  visited[i] = 0;
    TopSort(ALG);
    return 0;
}