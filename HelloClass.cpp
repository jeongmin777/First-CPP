#include <iostream>
using namespace std;
#include <string>


class MyStudent						// class declaration (선언부)
{
							// visibility accessibility (접근지정자)
private:
	string name;						// member variables (field)
	int num;
	void func() {
		num++;
	}
	

public:

	void printStudent();					// member function (method)
	void setStudent(string na, int n);

	MyStudent();							// default constructor (기본 생성자)
	MyStudent(string na);					// constructor overloading
	MyStudent(int n);
	MyStudent(string na, int n);

};

											// class definition (implementation 정의부/구현부)

MyStudent::MyStudent()						// 1. 자동 호출 (반드시 호출)
											// 2. 가장 먼저 호출
											// 3. 한 번만 호출
{
	name = "Default";
	num = 100;
}

MyStudent::MyStudent(string na)
{
	name = na;
	num = 200;
}
MyStudent::MyStudent(int n)
{
	name = "NoName...";
	num = n;
}
MyStudent::MyStudent(string na, int n)
{
	setStudent(na, n);
}

void MyStudent::printStudent()				// member function (method)
{
	cout << "[" << name << "] num=" << num << endl;
}
void MyStudent::setStudent(string na, int n)
{
	if (na == "") na = "NoName";
	if (n < 1) n = 1;

	name = na;
	num = n;
	func();
}


int main()
{

	MyStudent a;						// instance (object 객체) => Instanciation
	MyStudent b("Choi");
	
	a.printStudent();
	b.printStudent();

//	a.name = "Kim";
//	a.num = 10;
		
	
	a.setStudent("Kim", 10);
	a.printStudent();

	b = a;								// assignment (할당) != copy (복사)
	b.printStudent();

	MyStudent c(300);
	c.printStudent();

	MyStudent d("Park", 400);
	d.printStudent();

	return 0;
}