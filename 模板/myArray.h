#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T>
class myArray
{
public:
	//有参构造
	myArray(int capacity)
	{
		// cout << "有参构造" << endl;
		this->capacity = capacity;
		data = new T[this->capacity];
		this->size = 0;
	}

	//析构函数
	~myArray()
	{
		if (this->data)
		{
			// cout << "析构调用" << endl;
			delete []data;
		}
	}

	//拷贝构造函数
	myArray(const myArray& n_my_array)
	{
		// cout << "拷贝构造" << endl;
		this->capacity = n_my_array.capacity;
		this->size = n_my_array.size;
		this->data = new T(this->capacity);
		for (int i = 0; i < this->size; ++i)
		{
			this->data[i] = n_my_array.data[i];
		}
	}

	//尾插法
	void push_back(const T& val)
	{
		if (this->capacity == this->size)
		{
			return;
		} //Of if
		this->data[this->size++] = val;
	}

	//尾删法
	void Pop_back()
	{
		if (this->size == 0)
		{
			return;
		}
		this->size--;
	}

	int get_capacity() const
	{
		return capacity;
	}

	int get_size() const
	{
		return size;
	}

	T* get_data() const
	{
		return data;
	}

	//重载中括号
	T& operator[](int index)
	{
		return this->data[index];
	}

	myArray& operator=(const myArray& other)
	{
		// cout << "等号调用" << endl;
		if (this->data)
		{
			delete[]data;
			data = nullptr;
		}
		size = other.size;
		capacity = other.capacity;
		data = new T[capacity];
		for (int i = 0; i < this->size; ++i)
		{
			this->data[i] = other.data[i];
		}
		return *this;
	}


	friend bool operator==(const myArray& lhs, const myArray& rhs)
	{
		return lhs.data == rhs.data
			&& lhs.capacity == rhs.capacity
			&& lhs.size == rhs.size;
	}

	friend bool operator!=(const myArray& lhs, const myArray& rhs)
	{
		return !(lhs == rhs);
	}

private:
	T* data; //指针指向堆区开辟的真实数组

	int capacity; //数组容量

	int size; //数组大小
};
