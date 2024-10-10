#include <iostream>
using namespace std;
#include "LinkStack3.h"

int main()
{
	cout<<"请输入要转换的表达式："<<endl;
	char value;
	value=Sufix();
	cout<<"后缀表达式的值："<<(value-48)<<endl;
	return 0;
}
