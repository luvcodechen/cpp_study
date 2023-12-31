﻿#include "teacher.h"


string teacher::get_name()
{
	return name;
}

void teacher::set_name(string name_)
{
	name = name_;
}

int teacher::get_id()
{
	return id;
}

void teacher::set_id(int paraid)
{
	id = paraid;
}

/**
 * \brief 无参构造器
 */
teacher::teacher()
{
	id = 10;
	cout << "无参构造函数的调用。" << endl;
}

/**
 * \brief 有参构造器
 * \param a 参数
 */
teacher::teacher(int a)
{
	id = 100;
	cout << "有参构造函数的调用。" << endl;
}

teacher::teacher(const teacher& t)
{
	id = t.id;
	name = t.name;
}


teacher::~teacher()
{
	cout << "析造函数的调用。" << endl;
}
