#include <thread>
#include <iostream>
#include <memory>
#include <string>

#include "con.h"
#include "mute.h"
void printHelloWorld(std::string arg)
{
	std::cout << arg << std::endl;
}

void test1(int& a)
{
	a++;
	std::cout << a << std::endl;
}

std::thread t3;
int a = 1;

void test2()
{
	// int a = 1;
	t3 = std::thread(test1, std::ref(a));
	t3.join();
}

void test3(int* arg)
{
	std::cout << *arg << std::endl;
	delete arg;
}


class Mycalss
{
public:
	void fun()
	{
		std::cout << "hello world1" << std::endl;
		std::cout << "hello world2" << std::endl;
		std::cout << "hello world3" << std::endl;
	}
};


class Myclass1
{
private:
	friend void friend_fun(Myclass1 obj);

	void fun()
	{
		std::cout << "hello world111111" << std::endl;
	}
};


void friend_fun(Myclass1 obj)
{
	obj.fun();
}

int main()
{
		// std::thread thread1(printHelloWorld,"dfe ");
		// thread1.detach();
		// if (thread1.joinable())
			// thread1.join(); //���������̣��ȴ��߳�ִ�����

	// int a = 1;
	// std::thread thread2(test1, std::ref(a));//ref��������
	// thread2.join();

	// test2();

	// int* arg = new int(1);
	// std::thread thread3(test3, arg);
	// thread3.join();


	// Mycalss c1; 
	// std::thread t4(&Mycalss::fun,&c1); //�����߳�֮�󣬿�����ĳЩ�������c1��������ͷţ������߳��޷����ʳ����������ﲢ���ᱨ��
	// t4.join();
	// �������������ָ�����£�
	// std::shared_ptr<Mycalss> obj = std::make_shared<Mycalss>();
	// std::thread t4(&Mycalss::fun, obj);
	// t4.join();

	// Myclass1 obj;
	// std::thread t5(friend_fun, obj);
	// t5.join();

	// ������
	// mute_test();

	// ����
	// sisuo_test();

	// lock_guard
	// lock_guard_test();

	//unique_lock
	// unique_lock_test();

	// call_once
	// call_once_test();

	// condition var
	// condition_variable_test();

	return 0;

}
