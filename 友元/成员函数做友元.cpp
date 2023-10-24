#include  <iostream>
#include <string>

using namespace std;
class Person;


class ff
{
public:
	Person* p;

	ff();


	void visit(); // 让visit可以访问person中的私有成员

	void visit2(); // 让visit2不可以访问person中的私有成员
};

class Person
{
	friend void ff::visit(); // 成员函数做友元

public:
	Person(int age, int sexorientation) : age(age), sexorientation(sexorientation)
	{
	}

	int age = 20;

private:
	int sexorientation = 0;
};

ff::ff()
{
	p = new Person(10, 1);
}

void ff::visit()
{
	cout << "visit 正在访问 " << p->age << endl;
	cout << "visit 正在访问 " << p->sexorientation << endl;
}


void ff::visit2()
{
	cout << "visit2 正在访问 " << p->age << endl;
	// cout << "visit2 正在访问 " << p->sexorientation << endl;
}


void test()
{
	ff f;
	f.visit();
	f.visit2();
}

int main()
{
	test();
	return 0;
}
