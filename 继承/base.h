#pragma once
#include <iostream>
using namespace std;

//�̳еĻ���
class basepage
{
public:
	void header()
	{
		cout << "��ҳ����������¼��ע�ᡣ��������ͷ����" << endl;
	}

	void footer()
	{
		cout << "�������ġ�������ȫ��վ�ڵ�ͼ�����������ײ���" << endl;
	}

	void left()
	{
		cout << "java��py��cpp�������������б��֣�" << endl;
	}
	int sex;
protected:
	int age;

private:
	int money;
};
