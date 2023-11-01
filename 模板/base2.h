#pragma once
#include "iostream"
#include "string"
using namespace std;

//类模板成员函数的类外实现
template <class T1, class T2>
class base2
{
public:
	base2(T1 name, T2 age);
	void show();
	T1 name;
	T2 age;
};


template <class T1, class T2>
base2<T1, T2>::base2(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

template <class T1, class T2>
void base2<T1, T2>::show()
{
	cout << this->name << endl;
	cout << this->age << endl;
}

void test05()
{
	base2<string, int> b("sss", 2);
	b.show();
}
