#pragma once
#include <iostream>

using namespace std;

//������
class animal
{
public:
	int age;
};

//������̳н�����μ̳е����⣬
// �̳�֮ǰ�����Ϲؼ���virtual ��Ϊ��̳�
// animal���Ϊ��	����

//���� sheep
class sheep :virtual  public animal
{
public:

};

// ����
class tuo :virtual  public animal
{
public:

};


class yangtuo :public sheep, public tuo
{
public:

};
