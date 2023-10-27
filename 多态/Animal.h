#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal2
{
public:
	Animal2()
	{
		cout << "Animal2�Ĺ��캯��" << endl;
	}

	// // �������������Խ������ָ���޷� �ͷ��������
	// virtual ~Animal2()
	// {
	// 	cout << "Animal2����������" << endl;
	// }

	//�������������� ʵ��
	virtual ~Animal2() = 0;

	virtual void speak() = 0;
};

inline Animal2::~Animal2()
{
	cout << "Animal�Ĵ�����������" << endl;
}


class cat2 : public Animal2
{
public:
	cat2(const string& name)
	{
		cout << "cat2�Ĺ��캯��" << endl;
		this->name = new string(name);
	}

	void speak() override
	{
		cout << *name << " cat2 ��" << endl;
	}

	string* name;

	~cat2()
	{
		if (name != nullptr)
		{
			cout << "cat2 ����������" << endl;
			delete name;
			name = nullptr;
		}
	}
};
