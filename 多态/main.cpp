#include "iostream"
#include "calculator.h"
#include "base1.h"
#include "drink.h"
#include "Animal.h"
using namespace std;

class Animal
{
public:
	// �麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "cat��˵��" << endl;
	}
};

//��̬��̬����������1���м̳й�ϵ 2. ����Ҫ��д������麯��
// ��̬��̬ʹ�ã� �����ָ��������� ָ���������

void dospeak(Animal& animal)
{
	animal.speak();
}


void test1()
{
	Cat cat;
	dospeak(cat);
}

void test2()
{
	cout << "sizeof animal =" << sizeof(Animal) << endl;
}

void test3()
{
	Calculator c(10, 5);
	cout << c.getResult('+') << endl;
	cout << c.getResult('-') << endl;
	cout << c.getResult('*') << endl;
	cout << c.getResult('/') << endl;
}

void test4()
{
	abstravctCalculator_* cal = new addClass(10, 5);
	cout << cal->getResult();
	delete cal;
}

//���麯������
void test5()
{
	base1* b = new son1;
	b->fun();
}

//��̬��������
void test6()
{
	Drinking* drinking = new coffee;
	drinking->makeDrinking();
	delete drinking;
	drinking = new tea;
	drinking->makeDrinking();
	delete drinking;
}

void test7()
{
	Animal2* animal2 = new cat2("�ɻ�");
	animal2->speak();
	delete animal2;
}

int main()
{
	// test1();
	// test2();
	// cout << sizeof(int* ) << endl;
	// test3();
	// test4();
	// test5();
	// test6();
	test7();
	return 0;
}
