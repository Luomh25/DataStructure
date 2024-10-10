#include<iostream>   
#include"point.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
using namespace std;
void Point::move(int newX,int newY)
{
	x=newX;
	y=newY;
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}

Point Point::operator = (const Point& p)
{
	x=p.x;
	y=p.y;
	return *this;;
}

Point Point::operator+(const Point& p) 
{
	Point tp;
	tp.x=x+p.x;
	tp.y=y+p.y;
	return tp;
}
Point Point::operator*(const int i)
{
	Point tp;
	tp.x=x*i;
	tp.y=y*i;
	return tp;		
}
int Point::operator >(const Point& p)//比较它们距离原点的距离 
{	
	return (x*x+y*y)>(p.x*p.x+p.y*p.y)? 1:0 ;	
}
int Point::operator <(const Point& p)//比较它们距离原点的距离 
{	
	return (x*x+y*y)<(p.x*p.x+p.y*p.y)? 1:0 ;	
}
int Point::operator ==(const Point& p) 
{	
	return (x==p.x)&(y==p.y)? 1:0 ;	
}
ostream & operator << (ostream &output,  Point &p)
{
	output<<"("<<p.x<<","<<p.y<<")";
	return output;
}
istream & operator >> (istream&input, Point &p)
{
	input>>p.x>>p.y;
	return input;
}


