#pragma once
#include "base.h"


//basepage的子类java
class java : public basepage
{
public:
	void content()
	{
		cout << "java学科视频。。" << endl;
	}

	void fun()
	{
		sex = 10; // 公共成员可以访问，在子类依旧是公共成员
		age = 10; // 保护成员可以访问,在子类中依旧是保护成员
		// money = 10; 私有成员不能访问
	}
};

//子类python
class python : protected basepage
{
public:
	void content()
	{
		cout << "python学科视频" << endl;
	}

	void fun()
	{
		sex = 10; // 公共成员可以访问，在子类中是保护成员
		age = 10; // 保护成员可以访问，在子类中是保护成员
		// money = 10; //私有成员不可访问
	}
};

//子类cpp
class cpp : private basepage
{
public:
	void content()
	{
		cout << "cpp学科视频" << endl;
	}

	void fun()
	{
		sex = 10; // 公共成员可以访问，在子类中是私有成员
		age = 10; // 保护成员可以访问，在子类中是私有成员
		// money = 10; //私有成员不可访问
	}
};
