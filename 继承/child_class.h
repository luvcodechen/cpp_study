#pragma once
#include "base.h"


//basepage������java
class java : public basepage
{
public:
	void content()
	{
		cout << "javaѧ����Ƶ����" << endl;
	}

	void fun()
	{
		sex = 10; // ������Ա���Է��ʣ������������ǹ�����Ա
		age = 10; // ������Ա���Է���,�������������Ǳ�����Ա
		// money = 10; ˽�г�Ա���ܷ���
	}
};

//����python
class python : protected basepage
{
public:
	void content()
	{
		cout << "pythonѧ����Ƶ" << endl;
	}

	void fun()
	{
		sex = 10; // ������Ա���Է��ʣ����������Ǳ�����Ա
		age = 10; // ������Ա���Է��ʣ����������Ǳ�����Ա
		// money = 10; //˽�г�Ա���ɷ���
	}
};

//����cpp
class cpp : private basepage
{
public:
	void content()
	{
		cout << "cppѧ����Ƶ" << endl;
	}

	void fun()
	{
		sex = 10; // ������Ա���Է��ʣ�����������˽�г�Ա
		age = 10; // ������Ա���Է��ʣ�����������˽�г�Ա
		// money = 10; //˽�г�Ա���ɷ���
	}
};
