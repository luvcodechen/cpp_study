#pragma once
#include <iostream>
#include <mutex>
#include <thread>

class single;

class mute
{
public:
	int a = 0;
	std::mutex mte; // 互斥量。
	std::mutex mte1;

	void fun()
	{
		mte.lock();

		for (int i = 0; i < 1000000; i++)
			a++;
		mte.unlock();
	}

	void fun1()
	{
		int i = 0;
		while (i < 500)
		{
			mte.lock();
			mte1.lock();
			mte.unlock();
			mte1.unlock();
			i++;
		}
	}

	void fun2()
	{
		int i = 0;
		while (i < 500)
		{
			mte.lock();
			mte1.lock();
			mte1.unlock();
			mte.unlock();
			i++;
		}
	}
};

// a没有互斥访问，导致达不到想要的效果（a==20000)
void mute_test()
{
	mute m;
	std::thread t1(&mute::fun, &m);
	std::thread t2(&mute::fun, &m);

	t1.join();
	t2.join();
	std::cout << m.a << std::endl;
}


// 互斥量访问顺序导致死锁，先锁相同的，可以解决
void sisuo_test()
{
	mute m;
	std::thread t1(&mute::fun1, &m);
	std::thread t2(&mute::fun2, &m);

	t1.join();
	t2.join();
	std::cout << "over" << std::endl;
}

int shared_data = 0;
std::mutex mtx;

void fun()
{
	for (int i = 0; i < 10000; i++)
	{
		std::lock_guard<std::mutex> lg(mtx); // 无需手动解锁，析构函数会自动解锁
		shared_data++;
	}
}

std::timed_mutex mtx1;

void fun1()
{
	for (int i = 0; i < 2; i++)
	{
		// std::unique_lock<std::mutex> lg(mtx); // 无需手动解锁，析构函数会自动解锁，比lock guard多一些功能

		// std::unique_lock<std::mutex> lg(mtx,std::defer_lock); // 传入defer lock.,不会加锁 
		// lg.lock();

		//try lock for
		std::unique_lock<std::timed_mutex> lg(mtx1, std::defer_lock);
		if (lg.try_lock_for(std::chrono::seconds(2))) //等待2秒，还没有锁上就返回
		{
			std::this_thread::sleep_for(std::chrono::seconds(4)); // 线程休眠4s

			shared_data++;
		}
	}
}

void lock_guard_test()
{
	std::thread t1(fun);
	std::thread t2(fun);

	t1.join();
	t2.join();

	std::cout << shared_data << std::endl;
}

void unique_lock_test()
{
	std::thread t1(fun1);
	std::thread t2(fun1);

	t1.join();
	t2.join();

	std::cout << shared_data << std::endl;
}


static single* s = nullptr;
static std::once_flag once;

class single
{
public:
	single()
	{
	};

	single& operator=(const single& s) = delete;
	single(const single&) = delete;

	static single&  GetInstance()
	{
		std::call_once(once, init);

		return *s;
	}

	static void init()
	{
		if (!s) s = new single;
	}

	void print_(std::string msg)
	{
		std::cout << __TIME__ << ' ' << msg << std::endl;
	}
};

void fun_0()
{
	single::GetInstance().print_("error");
}

void call_once_test()
{
	std::thread t1(fun_0);
	std::thread t2(fun_0);

	t1.join();
	t2.join();
}
