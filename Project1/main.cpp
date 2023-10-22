#include <iostream>
#include <iostream>
using namespace std;
#include <string>
#include "teacher.h"

class Student
{
public:
	string get_name() const
	{
		return name;
	}

	int get_num() const
	{
		return num;
	}

	void set_name(const string& name)
	{
		this->name = name;
	}

	void set_num(int num)
	{
		this->num = num;
	}

	void to_string() const
	{
		cout << name << " " << num;
	}

private:
	string name;
	int num;
	int age = 10;
};

int main()
{
	// int* p = nullptr;
	// // cout << sizeof(p);
	// int a = 10, b = 30;
	// const int* p = &a;
	// a = 20;
	// p = &b;
	// *	 p=
	// std::cout << p << "\t" << *p;
	// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int* p = arr;
	// for (int i = 0; i < 10; ++i)
	// {
	// 	std::cout << p[i] << " ";
	// }/
	// Student student;
	// student.set_name("jief ");
	// student.set_num(23);
	// student.to_string(); 
	teacher t(10);
	cout << t.get_id() << endl; 
	t.set_id(20);
	t.set_name("john");
	teacher t2(t);
	cout << t2.get_id() << " " << t2.get_name()<< endl;
	system("pause"); 
	return 0;
}
