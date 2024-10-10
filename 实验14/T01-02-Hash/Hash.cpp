#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

const int Max = 11;
const char Empty = '#';
int HashSearch(int ht[], int m, int k, int &j, int &count);
void HashDelete(int ht[], int m, int x);

int main()
{
    int s[9] = {47, 7, 29, 11, 16, 92, 22, 8, 3};
    int ht[Max] = {0};
    int temp, i = 0, index = 0, count = 0;
    for ( i = 0; i < 9; i++)
    {
        HashSearch(ht, Max, s[i], index, count);
        cout<<"the index of the element "<<s[i]<<" is "<<index<<endl;
    }
    cout<<"the elements in the Hash: "<<endl;
    for ( i = 0; i < Max; i++)
        cout<<ht[i]<<" ";
    cout<<endl;
    srand(time(NULL));
    temp = 3;
    HashSearch(ht, Max, temp, index, count);
    cout<<"the index of the element "<<temp<<" is "<<index<<endl;
    cout<<"the amount of comparasion: "<<count<<endl;
    cout<<"Delete the element "<<temp<<endl;
    HashDelete(ht, Max, temp);
    cout<<"the elements in the Hash: "<<endl;
    for ( i = 0; i < Max; i++)
        cout<<ht[i]<<" ";
    cout<<endl;
    return 0;
}

int HashSearch(int ht[], int m, int k, int &j, int &count)
{
    int i;
    j = k % m;
    count = 1;
    if (ht[j] == k)  return 1;
    else if (ht[j] == 0)
        {
            ht[j] = k;
            return 0;
        }
    i = (j + 1) % m;
    while (ht[i] != 0 && i != j)
    {
        count++;
        if (ht[i] == k)
        {
            j = i;
            return 1;
        }
        else i = (i + 1) % m;
    }
    if (i == j)
    {
        cout<<"overflow!"<<endl;
        return 0;
    }
    else
    {
        ht[i] = k;
        j = i;
        return 0;
    }
}

void HashDelete(int ht[], int m, int x)
{
    int i, j = x % m, count = 0;
    if (ht[j] != x) i = (j + 1) % m;
    while (ht[i] != Empty && i != j)
    {
        if (ht[i] == x) break;
        else i = (i + 1) % m;
    }
    if (i == j)  cout<<"error! x no record"<<endl;
    else ht[j] = '#';
}