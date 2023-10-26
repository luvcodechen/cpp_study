#pragma once
#include <iostream>
using namespace std;

class base3
{
public:
	base3()
	{
		cout << "base3的构造函数" << endl;
		m = 10;
	}

	void fun()
	{
		cout << "base的fun函数" << endl;
	}

	~base3()
	{
		cout << "base3析构函数" << endl;
	}

	int m;
};

class son3 : public base3
{
public:
	son3()
	{
		cout << "son3的构造函数" << endl;
		m = 20;
	}

	void fun()
	{
		cout << "son的fun函数" << endl;
	}

	~son3()
	{
		cout << "son3的析构函数" << endl;
	}

	int m;
};
