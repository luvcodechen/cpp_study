#pragma once
#include <iostream>
#include <string>
using namespace std;

//ÀàÄ£°å
template <class NameType, class AgeType = int>
class my_class
{
public:
	my_class(const NameType& name, const AgeType& age)
	{
		this->name = name;
		this->age = age;
	}

	void show()
	{
		cout << "name= " << name << "," << "age= " << age << endl;
	}

	NameType name;
	AgeType age;
};
