#pragma once
#include <iostream>
using namespace std;

class my_print
{
public:
	//重载（）仿函数实现打印输出
	void operator()(const string test)
	{
		cout << test << endl;
	}
};
