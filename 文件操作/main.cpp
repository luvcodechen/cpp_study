// 创建时间： 2023/10/27 9:54:48

#include <iostream>
#include <fstream>
#include "string"
using namespace std;

//写文件
void test1()
{
	//1.包含头文件


	//2.创建流对象

	ofstream ofs;

	//3.指定打开方式

	ofs.open("test.txt", ios::out);

	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：20" << endl;

	ofs.close();
}


// 读文件
void test2()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open())
	{
		cout << "打开成功" << endl;
	}
	else
	{
		cout << "打开失败" << endl;
		return;
	}

	//读数据 第一种方法
	// char buf[1024];
	// while (ifs >> buf)
	// {
	// 	cout << buf << endl;
	// }

	// 第二种方法
	// char buf[1024];
	// while (ifs.getline(buf, sizeof(buf)))
	// {
	// 	cout << buf << endl;
	// }

	// 第三种方法
	// string buf;
	// while (getline(ifs, buf))
	// {
	// 	cout << buf << endl;
	// }

	//第四种方法

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

// 二进制文件， 写文件
void test3()
{
	// 创建流对象
	ofstream ofs("nyclass.txt", ios::out | ios::binary);

	// 写文件
	my_class1 c1 = { "张三", 18 };
	ofs.write((const char*)&c1, sizeof(my_class1));
	ofs.close();
}

// 二进制文件，读文件
void test4()
{
	ifstream ifs("nyclass.txt", ios::binary | ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
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
