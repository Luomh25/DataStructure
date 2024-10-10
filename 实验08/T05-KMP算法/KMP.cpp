#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int N = 100;

void GetNext(const char T[],int next[])
{
    next[0] = -1;
    int j = 0,k = -1;
    while (T[j] != '\0')
    {
        if (k = -1||T[j] ==T[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else k = next[k];
    }
}

int KMP(char S[],char T[],int next[])
{
    int i=0,j=0;
    while (T[j] != '\0' && S[i] != '\0')
    {
        if (T[j] == S[i]||j == -1)
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
    if (T[j] == '\0') return i-j+1;
    else return 0;
}

int main()
{
    char S[N],T[N];
    cout<<"S:"<<endl;
    cin>>S;
    cout<<"T:"<<endl;
    cin>>T;
    int next[N];
    GetNext(T,next);
    cout<<KMP(S,T,next)<<endl;
}