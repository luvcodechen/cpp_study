#include "teacher.h"


string teacher::get_name()
{
	return name;
}

void teacher::set_name(string name_)
{
	name = name_;
}

int teacher::get_id()
{
	return id;
}

void teacher::set_id(int paraid)
{
	id = paraid;
}

teacher::teacher()
{
	id = 10;
	cout << "���캯���ĵ��á�" << endl;
}

teacher::~teacher()
{
	cout << "���캯���ĵ��á�" << endl;
}
