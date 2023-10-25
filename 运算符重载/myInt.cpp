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
	myInt temp = *this; // 先记录当时结果

	m_num++; //再++
	return temp;
}
