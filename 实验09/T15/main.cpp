#include <iostream>
using namespace std;
const int MaxSize = 100;
void PreOrder(char * A, int n)
{
    int S[MaxSize] = {0};
    int top = -1;
    int i = 1;
    cout<<A[i - 1];
    S[++top] = i;
    int j = 2*i;
    while (A[j - 1] != '#' || top != -1)
    {
        while (j <= n && (A[j - 1] != '#'))
        {
            cout<<A[j - 1];
            S[++top] = j;
            i = j;
            j = 2*i;
        }
        i = S[top--];
        j = 2 * i + 1;
    }
}

int main()
{	
	int n;
	cin>>n;
	char seq[n] = {'#'};
	cin>>seq;
	PreOrder(seq, n);
	return 0;
}