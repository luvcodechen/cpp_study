#pragma once
#include <iostream>


using namespace std;

// �̳��еĶ���ģ��
class base02
{
public:
	int a;

protected:
	int b;

private:
	int c;
};

class son : public base02
{
public:
	int d;
};

//���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ����������˽�г�Ա���Ա����������أ����ʲ������������Ǳ��̳�
void size__()
{
	cout << "size of son= " << sizeof(son) << endl;
}
