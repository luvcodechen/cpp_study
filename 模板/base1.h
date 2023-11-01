#pragma once
#include	<iostream>
#include <locale>
#include <string>
using namespace std;
// 类模板与继承


template <class T>
class base1
{
public:
	T obj;
};

//必须知道父类中的T类型，才能集成给子类
class son1 : public base1<int>
{
};


//如果想要灵活指定父类中T类型，子类也需要是模板类
template <class T1, class T2>
class son2 : public base1<T1>
{
public:
	son2()
	{
		cout << "T1 的数据类型为:" << typeid(T1).name() << endl;
		cout << "T2 的数据类型为:" << typeid(T2).name() << endl;
	}

	T1 obj;

};
void test04()
{
	son2<int, char> s;
}