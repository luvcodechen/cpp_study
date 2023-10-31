#pragma once
//类模板对象做函数参数
#include <iostream>
using namespace std;


template <class T1, class T2>
class my_class1
{
public:
	my_class1(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

	void show()
	{
		cout << name << " " << age << endl;
	}

	T1 name;
	T2 age;
};

// 1.指定传入类型

void printclass1(my_class1<string, int>& c)
{
	c.show();
}

void test01()
{
	my_class1<string, int> c1("sss", 10);
	printclass1(c1);
}

// 2.参数模板化
template <class T1, class T2>
void printclass2(my_class1<T1, T2>& c)
{
	c.show();
	cout << typeid(T1).name() << " " << typeid(T2).name() << endl;
}


void test02()
{
	my_class1<string, int> c1("sjiu", 29);
	printclass2(c1);
}

// 3. 整个类模板化
template <class T>
void printclass3(T& c)
{
	c.show();
	cout << typeid(T).name() << endl;
}

void test03()
{
	my_class1<string, int> c("sjn", 28u);
	printclass3(c);
}
