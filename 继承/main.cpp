#include <iostream>
#include <string>

#include "child_class.h"
#include "base2.h"
#include "base3.h"
#include "base4.h"
//继承的基本语法测试
void test1()
{
	java j;
	j.header();
	j.footer();
	j.left();
	j.content();
	python p;
	// p.header(); // 改变继承类型后类外无法访问，下同
	// p.footer();
	// p.left();
	p.content();
	cpp c;
	// c.header();
	// c.footer();
	// c.left();
	c.content();
}

// 继承的三种方式测试
// void test2()
// {
//
// }

// 继承 中的构造和析构函数调用顺序
void test3()
{
	// base3 b;
	son3 son; // 先构造父类，在构造子类，然后先析构子类，再析构父类
}

//继承-同名成员处理
void test4()
{
	son3 son;
	cout << "son 下的m= " << son.m << endl;

	//如果通过子类对象访问父类里的同名属性，需要加作用域
	cout << "base 下的m= " << son.base3::m << endl;


	son.fun();
	son.base3::fun();
}

//继承-菱形继承问题
void test5()
{
	yangtuo yt;
	yt.sheep::age = 10;
	yt.tuo::age = 80;

	// 菱形继承，两个父类拥有相同数据，需要加上作用于加以区别
	cout << "yt.sheep::age= " << yt.sheep::age << endl;
	cout << "yt.tuo::age= " << yt.tuo::age << endl;
	cout << "yt.age= " << ytage << endl;


}

int main()
{
	// test1();
	// size__();
	// test3();
	// test4();
	test5();

	return 0;
}
