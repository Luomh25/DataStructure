#include <iostream>
using namespace std;
class Shape
{public:
 virtual double area()const=0;
};

//定义Circle类
class Circle:public Shape
{public:
	Circle(double r):radius(r){}
	virtual double area()const {return 3.14*radius*radius;}
 protected:
 	double radius;
};

//定义Square类
class Square:public Shape
{public:
	Square(double a):side(a){}
	virtual double area()const {return side*side;}
 protected:
 	double side;
};

//定义Rectangle类
class Rectangle:public Shape
{public:
	Rectangle(double w,double h):width(w),height(h){}
	virtual double area()const {return width*height;}
 protected:
 	double width,height;
};

//定义Trapezoid类
class Trapezoid:public Shape
{public:
	Trapezoid(double a,double b,double h):aside(a),bside(b),height(h){}
	virtual double area()const {return 0.5*height*(aside+bside);}
 protected:
 	double aside,bside,height;
};

//定义Triangle类
class Triangle:public Shape
{public:
	Triangle(double w,double h):width(w),height(h){}
	virtual double area()const {return 0.5*width*height;}
 protected:
 	double width,height;
}; 

int main()
{
	Circle circle(2);
	Square square(4);
	Rectangle rectangle(3,4);
	Trapezoid trapezoid(2,4,3);
	Triangle triangle(3,4);
	Shape *pt[5]={&circle,&square,&rectangle,&trapezoid,&triangle};
	double areas=0.0;
	for(int i=0;i<5;i++)
	{
		areas=areas+pt[i]->area();
	}
	cout<<"sum of all shapes = "<<areas<<endl;
	return 0;
}
