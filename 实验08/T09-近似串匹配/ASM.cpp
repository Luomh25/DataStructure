#include <iostream>
#include <iomanip>
using namespace std;
int D[50][50];

int Min(int a,int b,int c)
{
    int min = a;
    if (b < a) min = b;
    if (c < min) min = c;
    return min;
}

int ASM(char P[], char T[], int m, int n, int k)
{
    for (int j = 0; j <= n; j++)
        D[0][j] = 0;
    for (int i = 0; i <= m; i++)
        D[i][0] = i;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (P[i-1] == T[j-1])
                D[i][j] = Min(D[i-1][j-1], D[i-1][j]+1, D[i][j-1]+1);
            else
                D[i][j] = Min(D[i-1][j-1]+1, D[i-1][j]+1, D[i][j-1]+1);
        } 
    }
    int min=D[m][1];
	for(int j=1;j<=n;j++)
		if(min>D[m][j]) min=D[m][j];
	return min;
}

int length(char S[])
{
 	int l=0;
 	while(S[l]!='\0') {l++;}
 	l++; 
 	return l;
}

int main()
{  
	char P[100]="happy",T[100]="Have a hsppy day.";
	int k;
	cout<<"样本P:  "<<P<<endl;
	cout<<"样本T:  "<<T<<endl;
	cout<<"最小近似匹配为:  ";	
	cout<<ASM(P,T,length(P)-1,length(T)-1,k);
   	return 0;
}