#include "iostream"
#include "calculator.h"
#include "base1.h"
#include "drink.h"
#include "Animal.h"
using namespace std;

class Animal
{
public:
	// 虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "cat在说话" << endl;
	}
};

//动态多态满足条件：1。有继承关系 2. 子类要重写父类的虚函数
// 动态多态使用： 父类的指针或者引用 指向子类对象

void dospeak(Animal& animal)
{
	animal.speak();
}


void test1()
{
	Cat cat;
	dospeak(cat);
}

void test2()
{
	cout << "sizeof animal =" << sizeof(Animal) << endl;
}

void test3()
{
	Calculator c(10, 5);
	cout << c.getResult('+') << endl;
	cout << c.getResult('-') << endl;
	cout << c.getResult('*') << endl;
	cout << c.getResult('/') << endl;
}

void test4()
{
	abstravctCalculator_* cal = new addClass(10, 5);
	cout << cal->getResult();
	delete cal;
}

//纯虚函数测试
void test5()
{
	base1* b = new son1;
	b->fun();
}

//多态案例测试
void test6()
{
	Drinking* drinking = new coffee;
	drinking->makeDrinking();
	delete drinking;
	drinking = new tea;
	drinking->makeDrinking();
	delete drinking;
}

void test7()
{
	Animal2* animal2 = new cat2("飞机");
	animal2->speak();
	delete animal2;
}

int main()
{
	// test1();
	// test2();
	// cout << sizeof(int* ) << endl;
	// test3();
	// test4();
	// test5();
	// test6();
	test7();
	return 0;
}
