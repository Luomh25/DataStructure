#include <iostream>
using namespace std;
const int N = 5;

int main( )
{
	int A[N][N], SA[N * (N + 1) / 2] = {0};
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j <= i; j++)
			A[i][j] = A[j][i] = i + j;
    for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout<<A[i][j]<<"   ";
		cout<<endl;
	}
	for (i = 0; i < N; i++)
		for (j = 0; j <= i; j++)
			SA[i * (i - 1)/2 + j] = A[i][j];        //ѹ���洢
	cout<<endl<<"�������кź��кţ�";
	cin>>i>>j;
	cout<<endl<<i<<"��"<<j<<"�е�Ԫ��ֵ�ǣ�";
	i--;
	j--; 
	if (i >= j)
		cout<<SA[i * (i - 1)/2 + j]<<endl;
	else
		cout<<SA[j * (j - 1)/2 + i]<<endl;
	return 0;
}