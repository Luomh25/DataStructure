#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

const int Max = 11;

struct Node
{
    int data;
    Node * next;
};

const char Empty = '#';
int HashSearch(int ht[], int m, int k, int &j, int &count);
Node * HashSearch2(Node * ht2[], int m, int k,  int &count);

int main()
{
    int s[9] = {47, 7, 29, 11, 16, 92, 22, 8, 3};
    int ht[Max] = {0};
    Node * ht2[Max];
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

    cout<<"enter the element to search: ";
    cin>>temp;
    int p = HashSearch(ht, Max, temp, index, count);
    if (p == 1)
    {
        cout<<"success! the index of the element "<<temp<<" is "<<index<<endl;
        cout<<"the amount of comparasion (in closed hashing) is "<<count<<endl;
    }
    else  cout<<"fail! "<<endl;

    cout<<"----------------"<<endl;
    int count2 = 0;
    for ( i = 0; i < Max; i++)
        ht2[i] = NULL;
    for ( i = 0; i < 9; i++)
        Node * p = HashSearch2(ht2, Max, s[i], count2);
    Node *p2 = HashSearch2(ht2, Max, temp, count);
    if (p != NULL)
        cout<<"success! the amount of comparasion (in open hashing) is "<<count<<endl;
    else  cout<<"fail! "<<endl;
    
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

Node * HashSearch2(Node * ht2[], int m, int k,  int &count)
{
    int j = k % m;
    Node * p = ht2[j];
    count = 1;
    while (p != NULL && p -> data != k)
    {
        p = p -> next;
        count++;
    }
    if (p != NULL)
    {
        if (p -> data == k)  return p;
        else
        {
            Node * q = new Node;
            q -> data = k;
            q -> next = ht2[j];
            ht2[j] = q;
        }
    }
    if (p == NULL)
    {
        Node * q = new Node;
        q -> data = k;
        q -> next = ht2[j];
        ht2[j] = q;
    }
}