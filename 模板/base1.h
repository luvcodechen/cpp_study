#pragma once
#include	<iostream>
#include <locale>
#include <string>
using namespace std;
// ��ģ����̳�


template <class T>
class base1
{
public:
	T obj;
};

//����֪�������е�T���ͣ����ܼ��ɸ�����
class son1 : public base1<int>
{
};


//�����Ҫ���ָ��������T���ͣ�����Ҳ��Ҫ��ģ����
template <class T1, class T2>
class son2 : public base1<T1>
{
public:
	son2()
	{
		cout << "T1 ����������Ϊ:" << typeid(T1).name() << endl;
		cout << "T2 ����������Ϊ:" << typeid(T2).name() << endl;
	}

	T1 obj;

};
void test04()
{
	son2<int, char> s;
}