#pragma once
#include <iostream>
using namespace std;

class base3
{
public:
	base3()
	{
		cout << "base3�Ĺ��캯��" << endl;
		m = 10;
	}

	void fun()
	{
		cout << "base��fun����" << endl;
	}

	~base3()
	{
		cout << "base3��������" << endl;
	}

	int m;
};

class son3 : public base3
{
public:
	son3()
	{
		cout << "son3�Ĺ��캯��" << endl;
		m = 20;
	}

	void fun()
	{
		cout << "son��fun����" << endl;
	}

	~son3()
	{
		cout << "son3����������" << endl;
	}

	int m;
};
