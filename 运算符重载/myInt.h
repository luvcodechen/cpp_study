#pragma once
#include <iostream>
using namespace std;

class myInt
{
	friend ostream& operator<<(ostream& cout, const myInt& paramyint);

public:
	myInt()
	{
		m_num = 0;
	}

	// 重载前置++运算符
	myInt& operator++();
	// 重载后置++运算符
	myInt operator++(int);

	// 前置-- 重载	
	myInt& operator--()
	{
		m_num--;
		return *this;
	}

	// 后置-- 重载	
	myInt operator--(int)
	{
		myInt temp = *this;
		m_num--;
		return temp;
	}

private:
	int m_num;
};

// 只能运用全局函数去实现左移运算符
ostream& operator<<(ostream& cout, const myInt& paramyint);
