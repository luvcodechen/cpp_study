#pragma once
#include <iostream>

using namespace std;

//动物类
class Animal
{
public:
	int age;
};

//利用虚继承解决菱形继承的问题，
// 继承之前。加上关键子virtual 变为虚继承
// animal类变为虚	基类

//子类 sheep
class sheep :virtual  public Animal
{
public:

};

// 骆驼
class tuo :virtual  public Animal
{
public:

};


class yangtuo :public sheep, public tuo
{
public:

};
