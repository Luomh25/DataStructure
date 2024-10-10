#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
const int Max = 10;

struct TeleNumber
{
	string name;
	char landLine[10];
	char mobileNumber[12];
	char email[20];
} Tele[Max + 1];

int BinSearch(TeleNumber r[], int n, string find, int num[]) //从数组下标1开始存放待查集合
{
	int low = 1, high = n;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (find < r[num[mid]].name)  high = mid - 1;
		else if (find > r[num[mid]].name)  low = mid + 1;
		else  return mid;//查找成功，返回元素序号
	}
	return 0; //查找失败，返回0
}

void Sort(TeleNumber r[], int n, int num[])
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			int tj1 = num[j - 1];
			int tj2 = num[j];
			if (r[tj1].name > r[tj2].name)
				swap(num[j], num[j - 1]);
		}
	}
}

int main()
{
	freopen("a.txt", "r", stdin);
	int n, l, num[Max + 1];
	cout<<"Input the number of people"<<endl;
	cin>>n;
	cout<<"Inpyt name, landline, mobile, email: "<<endl;
	for (int i = 1; i <= n; i++)
	{
		cin>>Tele[i].name>>Tele[i].landLine>>Tele[i].mobileNumber>>Tele[i].email;
		num[i] = i;
	}
	Sort(Tele, n, num);

	cout<<"Find name: "<<endl;
	string find;
	cin>>find;
	l = BinSearch(Tele, n, find, num);
	cout<<endl;
	cout<<find<<endl<<"landline: "<<Tele[num[l]].landLine<<endl;
	cout<<"mobile: "<<Tele[num[l]].mobileNumber<<endl;
	cout<<"email: "<<Tele[num[l]].email<<endl;
	return 0;
}