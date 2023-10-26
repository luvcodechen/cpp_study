#pragma once
#include <iostream>
using namespace std;

//继承的基类
class basepage
{
public:
	void header()
	{
		cout << "首页、公开、登录、注册。。（公共头部）" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流安全、站内地图。。（公共底部）" << endl;
	}

	void left()
	{
		cout << "java、py、cpp。。。（公共列表部分）" << endl;
	}
	int sex;
protected:
	int age;

private:
	int money;
};
