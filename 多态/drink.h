#pragma once
#include <iostream>
using namespace std;

class  Drinking
{
public:
	//烧水
	virtual void Boil() = 0;

	//冲泡
	virtual void Brew() = 0;

	//导入杯中
	virtual void PourInCip() = 0;

	//加入佐料
	virtual void Putsomthing() = 0;

	// 制作饮品
	void makeDrinking()
	{
		Boil();
		Brew();
		PourInCip();
		Putsomthing();
	}
};

class coffee : public Drinking
{
public:
	void Boil() override
	{
		cout << "烧水" << endl;
	}

	void Brew() override
	{
		cout << "冲泡咖啡" << endl;
	}

	void PourInCip() override
	{
		cout << "导入杯中" << endl;
	}

	void Putsomthing() override
	{
		cout << "加奶" << endl;
	}
};


class tea : public Drinking
{
public:
	void Boil() override
	{
		cout << "烧水" << endl;
	}

	void Brew() override
	{
		cout << "冲茶叶" << endl;
	}

	void PourInCip() override
	{
		cout << "导入杯中" << endl;
	}

	void Putsomthing() override
	{
		cout << "再加水" << endl;
	}
};
