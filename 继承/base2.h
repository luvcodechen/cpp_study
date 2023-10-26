#pragma once
#include <iostream>


using namespace std;

// 继承中的对象模型
class base02
{
public:
	int a;

protected:
	int b;

private:
	int c;
};

class son : public base02
{
public:
	int d;
};

//父类中所有非静态成员属性都会被子类继承下去。。父类中私有成员属性被编译器隐藏，访问不到，但依旧是被继承
void size__()
{
	cout << "size of son= " << sizeof(son) << endl;
}
