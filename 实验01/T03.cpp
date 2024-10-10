#include <iostream>
using namespace std;

class Shape
{public:
 virtual double area() const=0;
};

//定义Circle类
class Circle:public Shape
{public:
	Circle(double r):radius(r){}
	virtual double area()const {return 3.14*radius*radius;}
 protected:
 	double radius;
};

//定义Rectangle类
class Rectangle:public Shape
{public:
	Rectangle(double a,double b):aside(a),bside(b){}
	virtual double area()const {return aside*bside;}
 protected:
 	double aside,bside;
};

//定义Triangle类
class Triangle:public Shape
{public:
	Triangle(double w,double h):width(w),height(h){}
	virtual double area()const {return 0.5*width*height;}
 protected:
 	double width,height;
};

void printArea(const Shape&s)
	{cout<<s.area()<<endl;}
int main()
{
	Circle circle(2);
	cout<<"area of circle    = ";
	printArea(circle);
	
	Rectangle rectangle(3,4);
	cout<<"area of rectangle = ";
	printArea(rectangle);
	
	Triangle triangle(3,4);
	cout<<"area of triangle  = ";
	printArea(triangle);
	
	return 0;
}
