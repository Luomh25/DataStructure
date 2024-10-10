#include <iostream>
#include <string>
using namespace std;
class teacher
{
	public:
		teacher(string nam,int a,char s,string add,string tel,string til)
		{
			name=nam;
			age=a;
			sex=s;
			address=add;
			telephone=tel;
			title=til;
		}
		void display();
	protected:
		string name;
		int age;
		char sex;
		string address;
		string telephone;
		string title;
};
void teacher::display()
{
	cout<<"name��"<<name<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"address:"<<address<<endl;
	cout<<"telephone:"<<telephone<<endl;
	cout<<"title:"<<title<<endl;
	
}
class cadre
{
	public:
		cadre(string nam1,int a1,char s1,string add1,string tel1,string pos)
		{
			name=nam1;
			age=a1;
			sex=s1;
			address=add1;
			telephone=tel1;
			post=pos;
		}
		void display1();
		cadre(string pos)
		{
			post=pos;
		}

	
	protected:
		string post;
		string name;
		int age;
		char sex;
		string address;
		string telephone;
		int wages;
		
		
};
void cadre::display1()
{
	cout<<"name��"<<name<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"address:"<<address<<endl;
	cout<<"telephone:"<<telephone<<endl;
	
	cout<<"post:"<<endl;
}

class teacher_cadre:public teacher, public cadre
{
	public:
	teacher_cadre
	(string nam,int a,char s,string add,
	string tel,string til,string pos,int wag):
	teacher(nam,a,s,add,tel,til), 
	cadre(pos),
	wages(wag)
	{ }
	
		void show();
	protected:
		int wages;
		
		
};
void teacher_cadre::show()
{
	display();
	cout<<"post:"<<post<<endl;
	cout<<"wages:"<<wages<<endl;
}

int main()
{
	teacher_cadre 
	a1("ZHANGli",21,'m',"shanghai","1234567","teacher","headmaster",9999);
	a1.show();
	return 0;
}

