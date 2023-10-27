#pragma once
#include <iostream>
using namespace std;

class  Drinking
{
public:
	//��ˮ
	virtual void Boil() = 0;

	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PourInCip() = 0;

	//��������
	virtual void Putsomthing() = 0;

	// ������Ʒ
	void makeDrinking()
	{
		Boil();
		Brew();
		PourInCip();
		Putsomthing();
	}
};

class coffee : public Drinking
{
public:
	void Boil() override
	{
		cout << "��ˮ" << endl;
	}

	void Brew() override
	{
		cout << "���ݿ���" << endl;
	}

	void PourInCip() override
	{
		cout << "���뱭��" << endl;
	}

	void Putsomthing() override
	{
		cout << "����" << endl;
	}
};


class tea : public Drinking
{
public:
	void Boil() override
	{
		cout << "��ˮ" << endl;
	}

	void Brew() override
	{
		cout << "���Ҷ" << endl;
	}

	void PourInCip() override
	{
		cout << "���뱭��" << endl;
	}

	void Putsomthing() override
	{
		cout << "�ټ�ˮ" << endl;
	}
};
