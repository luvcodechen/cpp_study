#pragma once
#include <iostream>
using namespace std;

class myInt
{
	friend ostream& operator<<(ostream& cout, const myInt& paramyint);

public:
	myInt()
	{
		m_num = 0;
	}

	// ����ǰ��++�����
	myInt& operator++();
	// ���غ���++�����
	myInt operator++(int);

	// ǰ��-- ����	
	myInt& operator--()
	{
		m_num--;
		return *this;
	}

	// ����-- ����	
	myInt operator--(int)
	{
		myInt temp = *this;
		m_num--;
		return temp;
	}

private:
	int m_num;
};

// ֻ������ȫ�ֺ���ȥʵ�����������
ostream& operator<<(ostream& cout, const myInt& paramyint);
