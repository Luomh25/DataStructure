//Point.h  点类的定义 
#ifndef _POINT_H
#define _POINT_H
#include <iostream>
using namespace std;
class Point {	             //类的定义
 public:	  	             //外部接口
    Point() 				 //无参构造函数
	{
		x=0;y=0;
	} 	            
	Point(int X, int Y)		//有参构造函数
	{
		x=X,y=Y;
	}
	~Point() 				//析构造函数
	{
	//	cout<<"删除"<<"("<<x<<","<<y<<")点。"<<endl;
	}           
    Point(const Point &p)  //复制构造函数;
    {
    	x=p.x;y=p.y;
	}
    void move(int newX,int newY);  //点值变为新的值 
    int getX();//获取x值
	int getY();//获取y值
    Point operator = (const Point & p); //重载赋值运算符
    Point operator + (const Point& p);  //重载+运算符:当前对象+参数中对象p 
    Point operator * (const int i);  //重载*运算符:当前对象*参数表中整数i
	int operator >(const Point& p) ; //重载>运算符:判断当前对象>参数中对象p
    int operator <(const Point& p) ; //重载<运算符:判断当前对象<参数中对象p否 
	int operator ==(const Point& p); //重载==运算符:判断当前对象=参数中对象p否  
    friend istream &operator >> (istream &input, Point &p);   //运算符<<重载	
    friend ostream &operator << (ostream &output, Point &p);  //运算符<<重载	

  private:				//私有数据成员
	int x, y;
};
#endif	//_POINT_H


