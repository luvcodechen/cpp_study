// ����ʱ�䣺 2023/10/27 11:52:46

#include <iostream>
using namespace std;
//����ģ��
template <typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//����ģ��test
void test1()
{
	int a = 10;
	int b = 20;

	//�Զ������Ƶ�
	// myswap(a, b);
	// cout << a << " " << b << endl;

	//��ʽָ������
	myswap<int>(a, b);
	cout << a << " " << b << endl;
}


int main()
{
	test1();
	return 0;
}
