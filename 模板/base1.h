#pragma once
#include	<iostream>
#include <string>
using namespace std;
// ��ģ����̳�



template <class T>
class base1
{
public:
	T obj;
};


class son1 :public base1<int>
{

};


