#pragma once
#include <iostream>

using namespace std;

//������
class Animal
{
public:
	int age;
};

//������̳н�����μ̳е����⣬
// �̳�֮ǰ�����Ϲؼ���virtual ��Ϊ��̳�
// animal���Ϊ��	����

//���� sheep
class sheep :virtual  public Animal
{
public:

};

// ����
class tuo :virtual  public Animal
{
public:

};


class yangtuo :public sheep, public tuo
{
public:

};
