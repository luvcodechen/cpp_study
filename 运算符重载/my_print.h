#pragma once
#include <iostream>
using namespace std;

class my_print
{
public:
	//���أ����º���ʵ�ִ�ӡ���
	void operator()(const string test)
	{
		cout << test << endl;
	}
};
