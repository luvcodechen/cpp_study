#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal2
{
public:
	Animal2()
	{
		cout << "Animal2的构造函数" << endl;
	}

	// // 利用虚析构可以解决父类指针无法 释放子类对象
	// virtual ~Animal2()
	// {
	// 	cout << "Animal2的析构函数" << endl;
	// }

	//纯虚析构，必须 实现
	virtual ~Animal2() = 0;

	virtual void speak() = 0;
};

inline Animal2::~Animal2()
{
	cout << "Animal的纯虚析构函数" << endl;
}


class cat2 : public Animal2
{
public:
	cat2(const string& name)
	{
		cout << "cat2的构造函数" << endl;
		this->name = new string(name);
	}

	void speak() override
	{
		cout << *name << " cat2 喵" << endl;
	}

	string* name;

	~cat2()
	{
		if (name != nullptr)
		{
			cout << "cat2 的析构函数" << endl;
			delete name;
			name = nullptr;
		}
	}
};
