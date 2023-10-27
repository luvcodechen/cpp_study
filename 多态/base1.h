#pragma once

#include <iostream>

using namespace std;

class base1
{
public:
	//纯虚函数
	// 只要有一个纯虚函数，这个类就是抽象类
	// 抽象类特点： 1.无法实例化对象
	//		       2.抽象类的子类，必须重写虚函数，不然也是抽象类
	virtual void fun() = 0;
};


class son1 : public base1
{
public:
	void fun() override
	{
		cout << "纯虚函数测试" << endl;
	}
};
