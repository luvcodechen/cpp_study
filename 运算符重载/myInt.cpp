#include "myInt.h"

ostream& operator<<(ostream& cout, const myInt& paramyint)
{
	cout << paramyint.m_num;
	return cout;
}

myInt& myInt::operator++()
{
	m_num++;

	return *this;
}

myInt myInt::operator++(int)
{
	myInt temp = *this; // �ȼ�¼��ʱ���

	m_num++; //��++
	return temp;
}
