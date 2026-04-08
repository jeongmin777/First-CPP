#include <iostream>
using namespace std;

#include <string>
#include "myFunction.h"


int g_count;			// global variable

class MyCircle
{
private:
	int m_x, m_y;		// Hungarian Notation (Naming convention)
	float m_radius;
	string m_name;
	
public:
	MyCircle();							// 기본 생성자(default constructor)
	MyCircle(int x, int y, float r, string name);
	MyCircle(string name);				// 생성자 중복(Constructor Overloading)
	~MyCircle();						// 소멸자 (Destructor)

	void print();

	// getter (accessor)
	float getRadius()					{ return m_radius; }
	int getX()							{ return m_x; }
	int getY()							{ return m_y; }
	string getName()					{ return m_name; }

	// setter (mutator)
	void setPosition(int x, int y)		{ m_x = x; m_y = y; }
	void setRadius(float r)				{ m_radius = r; }

};

MyCircle::MyCircle()				// 1. 가장 먼저 호출 2. 반드시 호출 3. 한 번만 호출
{
	m_x = 0;
	m_y = 0;
	m_radius = 1;
	m_name = "NoName";

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			cout << i << " * " << j << " = " << i * j << " | ";
		cout << endl;
	}

	cout << "[CONSTRUCTOR:" << m_name << "] default" << endl;
}
MyCircle::MyCircle(string name)	
{
	m_x = 0;
	m_y = 0;
	m_radius = 1;
	m_name = name;
	cout << "[CONSTRUCTOR:" << m_name << "] 1" << endl;
}

MyCircle::MyCircle(int x, int y, float r, string name)
{
	m_x = x;
	m_y = y;
	m_radius = r;
	m_name = name;
	cout << "[CONSTRUCTOR:" << m_name << "] 2" << endl;
}

MyCircle::~MyCircle()
{
	cout << "[DESTRUCTOR:" << m_name << "]" << endl;
}



void MyCircle::print()
{
	cout << "[CIRCLE:" << m_name << "] (" << m_x << "," << m_y << ") r=" << m_radius << endl;
}


MyCircle g_0;
MyCircle g_a("G_A");

void func()
{
	MyCircle fa("F_A");
	MyCircle fb("F_B");
}

#include "myFunction.h"

int main()
{
	myFunction1();
	
	MyCircle a("A");
	MyCircle b(10, 20, 3, "B");
	float r = a.getRadius();
	r = 4.0f;
	cout << a.getRadius() << endl;



	for(int i = 0; i<3; i++)
	{							// SCOPE (변수의 생애주기)
		MyCircle c("C");
	}

	a.print();
	b.print();


	func();

	return 0;
}

MyCircle g_b("G_B");
