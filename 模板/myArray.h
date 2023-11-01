#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T>
class myArray
{
public:
	//�вι���
	myArray(int capacity)
	{
		// cout << "�вι���" << endl;
		this->capacity = capacity;
		data = new T[this->capacity];
		this->size = 0;
	}

	//��������
	~myArray()
	{
		if (this->data)
		{
			// cout << "��������" << endl;
			delete []data;
		}
	}

	//�������캯��
	myArray(const myArray& n_my_array)
	{
		// cout << "��������" << endl;
		this->capacity = n_my_array.capacity;
		this->size = n_my_array.size;
		this->data = new T(this->capacity);
		for (int i = 0; i < this->size; ++i)
		{
			this->data[i] = n_my_array.data[i];
		}
	}

	//β�巨
	void push_back(const T& val)
	{
		if (this->capacity == this->size)
		{
			return;
		} //Of if
		this->data[this->size++] = val;
	}

	//βɾ��
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

	//����������
	T& operator[](int index)
	{
		return this->data[index];
	}

	myArray& operator=(const myArray& other)
	{
		// cout << "�Ⱥŵ���" << endl;
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
	T* data; //ָ��ָ��������ٵ���ʵ����

	int capacity; //��������

	int size; //�����С
};
