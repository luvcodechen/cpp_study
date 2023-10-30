// 创建时间： 2023/10/27 11:52:46

#include <iostream>
using namespace std;
//函数模板
template <typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//函数模板test
void test1()
{
	int a = 10;
	int b = 20;

	//自动类型推导
	// myswap(a, b);
	// cout << a << " " << b << endl;

	//显式指定类型
	myswap<int>(a, b);
	cout << a << " " << b << endl;
}


int main()
{
	test1();
	return 0;
}
