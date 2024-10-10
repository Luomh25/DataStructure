#include <iostream>
using namespace std;
#include "MGraph.cpp"

int visited[10];

int main()
{
    string ch[] = {"0000", "0100", "0010", "0001", "1001","0110", "1110", "1101", "1011", "1111"};
    MGraph G(ch);
    for (int i = 0; i < 10; i++)
        visited[i] = 0;
    G.Path();
    return 0;
}