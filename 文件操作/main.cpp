// ����ʱ�䣺 2023/10/27 9:54:48

#include <iostream>
#include <fstream>
#include "string"
using namespace std;

//д�ļ�
void test1()
{
	//1.����ͷ�ļ�


	//2.����������

	ofstream ofs;

	//3.ָ���򿪷�ʽ

	ofs.open("test.txt", ios::out);

	//4.д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺20" << endl;

	ofs.close();
}


// ���ļ�
void test2()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open())
	{
		cout << "�򿪳ɹ�" << endl;
	}
	else
	{
		cout << "��ʧ��" << endl;
		return;
	}

	//������ ��һ�ַ���
	// char buf[1024];
	// while (ifs >> buf)
	// {
	// 	cout << buf << endl;
	// }

	// �ڶ��ַ���
	// char buf[1024];
	// while (ifs.getline(buf, sizeof(buf)))
	// {
	// 	cout << buf << endl;
	// }

	// �����ַ���
	// string buf;
	// while (getline(ifs, buf))
	// {
	// 	cout << buf << endl;
	// }

	//�����ַ���

	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close();
}

class my_class1
{
public:
	char name[64];

	int age;
};

// �������ļ��� д�ļ�
void test3()
{
	// ����������
	ofstream ofs("nyclass.txt", ios::out | ios::binary);

	// д�ļ�
	my_class1 c1 = { "����", 18 };
	ofs.write((const char*)&c1, sizeof(my_class1));
	ofs.close();
}

// �������ļ������ļ�
void test4()
{
	ifstream ifs("nyclass.txt", ios::binary | ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	my_class1 c1;
	ifs.read((char*)&c1, sizeof(my_class1));
	cout << c1.name << " " << c1.age << endl;

	ifs.close();
}

int main()
{
	// test1();
	// test2();
	// test3();
	test4();
	return 0;
}
