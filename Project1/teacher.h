#pragma once
#include <iostream>
#include <string>
using namespace std;

class teacher
{
	private:
		string name;
		int id;

	public:
		string get_name();


		void set_name(string name);


		int get_id();


		void set_id(int id);

		teacher();


		~teacher();

};
