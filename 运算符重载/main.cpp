#include <iostream>
using namespace std;
#include "myInt.h"
#include "my_print.h"

class Person
{
public:
	Person(int m_a, int m_b) : m_a(m_a),
		m_b(m_b)
	{
	}

	Person()
	{
	}

	int m_a;
	int m_b;

	// +运算符重载
	Person operator+(const Person& p) const
	{
		Person t_person;
		t_person.m_a = this->m_a + p.m_a;
		t_person.m_b = this->m_b + p.m_b;
		return t_person;
	}
};

class stu
{
public:
	stu(int para_age)
	{
		age = new int(para_age);
	}

	stu& operator=(const stu& para_p)
	{
		// 编译器是提供浅拷贝
		//age=para_p.age

		//应该先判断自己有没有开辟堆区，如果有先释放，然后进行深拷贝
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		} //OF if

		age = new int(*para_p.age);

		// 返回对象本身
		return *this;
	}

	~stu()
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
	}

	int* age;
};


class Cat
{
public:
	Cat(const int& age, const string& name)
	{
		this->age = age;
		this->name = name;
	}

	//重载关系运算符==
	bool operator==(Cat& c)
	{
		return this->age == c.age && this->name == c.name;
	} //重载关系运算符==
	bool operator!=(Cat& c)
	{
		return !(this->age == c.age && this->name == c.name);
	}

	int age;
	string name;
};

// Person operator+(Person para_p1, Person para_p2)
// {
// 	Person tempP;
// 	tempP.m_a = para_p1.m_a + para_p2.m_a;
// 	tempP.m_b = para_p1.m_b + para_p2.m_b;
// 	return tempP;
// }

// +函数重载
Person operator+(Person person, int num)
{
	Person t_person;
	t_person.m_a = person.m_a + num;
	t_person.m_b = person.m_b + num;
	return t_person;
}

// 只能运用全局函数去实现左移运算符
ostream& operator<<(ostream& cout, const Person& p)
{
	cout << "m_a= " << p.m_a << " m_b= " << p.m_b << endl;
	return cout;
}

// +重载测试
void test1()
{
	Person p1(5, 4);
	Person p2(5, 4);
	Person p3 = p1 + p2;
	std::cout << p3.m_a << "  " << p3.m_b << std::endl;
	p3 = p3 + 10;
	std::cout << p3.m_a << "  " << p3.m_b << std::endl;
}

// <<重载测试
void test2()
{
	Person p1(1, 2);
	cout << p1 << endl;
}

//++运算符重载测试
void test3()
{
	myInt my_int;
	cout << "my_int= " << my_int << endl;
	cout << "前++： " << ++my_int << endl;
	cout << "后++： " << my_int++ << endl;
	cout << "my_int= " << my_int << endl;
}


//-- 重载测试
void test4()
{
	myInt my_int;
	cout << "my_int= " << my_int << endl;
	cout << "前--： " << --my_int << endl;
	cout << "后--： " << my_int-- << endl;
	cout << "my_int= " << my_int << endl;
}


// =重载测试
void test5()
{
	stu s1(10);
	stu s2(20);
	s2 = s1;
	// stu s3 = s2;// 报错
	stu s3(29290);
	s3 = s2 = s1;
	cout << "s1.age= " << *s1.age << endl;
	cout << "s2.age= " << *s2.age << endl;
	cout << "s3.age= " << *s3.age << endl;
}


//==重载测试
void test6()
{
	Cat c1(1, "黄牛");
	Cat c2(1, "牛");

	if (c1 == c2)
	{
		cout << "相等 " << "c1.name=" << c1.name << "\t" << "c2.name = " << c2.name << endl;
	}
	else if (c1 != c2)
	{
		cout << "不相等" << endl;
	}
}


//()重载测试
void test7()
{
	my_print mp;
	mp("hello world");
}

// main 函数
int main()
{
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	test7();
	return 0;
	
}
