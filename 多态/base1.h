#pragma once

#include <iostream>

using namespace std;

class base1
{
public:
	//���麯��
	// ֻҪ��һ�����麯�����������ǳ�����
	// �������ص㣺 1.�޷�ʵ��������
	//		       2.����������࣬������д�麯������ȻҲ�ǳ�����
	virtual void fun() = 0;
};


class son1 : public base1
{
public:
	void fun() override
	{
		cout << "���麯������" << endl;
	}
};
