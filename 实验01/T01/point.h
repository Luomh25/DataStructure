//Point.h  ����Ķ��� 
#ifndef _POINT_H
#define _POINT_H
#include <iostream>
using namespace std;
class Point {	             //��Ķ���
 public:	  	             //�ⲿ�ӿ�
    Point() 				 //�޲ι��캯��
	{
		x=0;y=0;
	} 	            
	Point(int X, int Y)		//�вι��캯��
	{
		x=X,y=Y;
	}
	~Point() 				//�����캯��
	{
	//	cout<<"ɾ��"<<"("<<x<<","<<y<<")�㡣"<<endl;
	}           
    Point(const Point &p)  //���ƹ��캯��;
    {
    	x=p.x;y=p.y;
	}
    void move(int newX,int newY);  //��ֵ��Ϊ�µ�ֵ 
    int getX();//��ȡxֵ
	int getY();//��ȡyֵ
    Point operator = (const Point & p); //���ظ�ֵ�����
    Point operator + (const Point& p);  //����+�����:��ǰ����+�����ж���p 
    Point operator * (const int i);  //����*�����:��ǰ����*������������i
	int operator >(const Point& p) ; //����>�����:�жϵ�ǰ����>�����ж���p
    int operator <(const Point& p) ; //����<�����:�жϵ�ǰ����<�����ж���p�� 
	int operator ==(const Point& p); //����==�����:�жϵ�ǰ����=�����ж���p��  
    friend istream &operator >> (istream &input, Point &p);   //�����<<����	
    friend ostream &operator << (ostream &output, Point &p);  //�����<<����	

  private:				//˽�����ݳ�Ա
	int x, y;
};
#endif	//_POINT_H


