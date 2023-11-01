// 创建时间： 2023/10/27 11:52:46

#include <iostream>
#include <string>
#include <vector>

#include  "tempclass.h"
#include  "class_obj.h"
#include "base1.h"
#include "base2.h"
#include "myArray.h"
using namespace std;

// 普通函数与函数模板调用规则
// 1。如果函数模板和普通函数都可以调用，优先调用普通函数
// 2.可以通过空模板参数列表强制调用函数模板
// 3. 函数模板可以发生函数重载
// 4. 如果函数模板可以产生更好的匹配，优先调用函数模板

class person
{
public:
	person(const string& name, const int& age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};


//函数模板
template <typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <typename T>
bool is_eq(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//利用具体person 的版本实现代码，具体化优先调用
template <>
bool is_eq(person& p1, person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//函数模板test
void test1()
{
	int a = 10;
	int b = 20;

	//自动类型推导
	// myswap(a, b);
	// cout << a << " " << b << endl;

	//显式指定类型
	myswap<int>(a, b);
	cout << a << " " << b << endl;
}

// 函数模板
void test2()
{
	int a = 10;
	int b = 20;
	// cout << is_eq(a, b) << endl;

	person p1("tom", 10);
	person p2("DD", 20);

	cout << is_eq(p1, p2) << endl;
}


//类模版
void test3()
{
	my_class<string, int> c1("射弩苏", 28);
	cout << c1.name << " " << c1.age << endl;
	c1.show();
}

//类模板与函数模板区
//1.类模板没有自动类型推导使用方式
void test4()
{
	// my_class c1("ss", 20);  错误的，不能自动类型推导，
	my_class<string, int> c1("sbnj ", 10);
	c1.show();
}

//2.类模板在模板参数列表中可以有默认参数
void test5()
{
	my_class<string> c1("sdhbj ", 90);
	c1.show();
}

void test6()
{
	test01();
	test02();
	test03();
}

//类模板与继承
void test7()
{
	test04();
}

void test8()
{
	// 问题： 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
	// 解决方式1： 包含cpp源文件
	// 解决方式2： 将声明和实现写在一起，文件后缀名改为.hpp
}

void printArray(myArray<int>& data)
{
	for (int i = 0; i < data.get_size(); ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}


void test9()
{
	myArray<int> arr1(5);
	// myArray<int> arr2(arr1);
	// myArray<int >arr3(100);
	// arr3 = arr1;

	for (int i = 0; i < 5; ++i)
	{
		arr1.push_back(i);
	}
	printArray(arr1);
	cout << arr1.get_capacity() << " " << arr1.get_size() << endl;
	arr1.Pop_back();
	printArray(arr1);
}

int main()
{
	// test1 ();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	// test7();
	// test05
	// test9();
	return 0;
}
